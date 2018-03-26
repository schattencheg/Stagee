#include "FindInterval.h"

FindInterval::FindInterval() {}

vector<pair<double, double>> FindInterval::findIntervals(const ContDiffFunction *f,
                    double left, double right, AbstractSolver &solver) {
  int maxIterationCount = 10000;
  double vMax = (right - left) / 1000; //Highest Dx
  vector<double> values;
  /*Fills random, sorted points*/
  int countToGenerate = static_cast<int>((right - left) * 20 );
  for (int i = 0; i < countToGenerate; i++) {
    double rndTmp = (double)rand() / RAND_MAX;
    values.push_back(left + rndTmp * (right - left));
    //double tmp = (left + i * (right - left) / countToGenerate);
    //values.push_back(tmp);
  }
  sort(values.begin(), values.end());

  vector<pair<double, double>> intervals;

  /**/
  for (unsigned int i = 0; i < values.size(); i++) {
    double f0; //Function value
    double f1; //Derivative value
    double b0; //Sign(f0)
    double b1; //Dign(f1)
    double v;  //Step
    /*Initialization*/
    double xPrev = values[i];
    double sPrev = 0;
    double sNext = sPrev;
    double xNext = xPrev;
    int iteration = 0;
    /*Main loop*/
    while ((iteration < maxIterationCount) && (xNext <= right) && (xNext >= left)) {
      f0 = f->value(xPrev);
      f1 = f->derivValue(xPrev);

      b0 = f0 >= 0 ? 1 : -1;
      b1 = f1 >= 0 ? 1 : -1;

      sNext = -b0 * b1;
      v = vMax;//min(max(d, f0 / f1), vMax);
      xNext = xPrev + sNext * v;

      if (solver.isRoot(f,xPrev)){intervals.push_back(make_pair(xPrev, xPrev)); break;}
      if (solver.isRoot(f,xNext)){intervals.push_back(make_pair(xNext, xNext)); break;}

      if ((i>0)&&(xNext<values[i-1])&&(xPrev<values[i-1]))break; /*We already calculated it, so skip*/

      if (sNext * sPrev == -1) {
        /*We found it*/
        intervals.push_back(make_pair(min(xPrev, xNext), max(xPrev, xNext)));
        break;
      }
      sPrev = sNext;
      xPrev = xNext;
      iteration++;
    }
    /* UNNECESSARY INCREASING PERFORMANCE */
    while ((i<values.size()-1)&&(values[i]<min(xPrev, xNext)))i++;
  }

  /*Combine intervals */
  for (unsigned int i = 0; i < intervals.size(); i++) {
    for (unsigned int j = i + 1; j < intervals.size(); j++) {
      // Checking this two intervals (i and j) is same
      //      i     [0,      1]
      //      j           [0,        1]
      pair<double, double> intersection;
      pair<double, double> first = intervals[i];
      pair<double, double> second = intervals[j];
      if ((first.first <= second.second + solver.epsilon) &&
          (first.second >= second.first - solver.epsilon)) {
        intersection.first = min(first.first, second.first);
        intersection.second = max(first.second, second.second);
        /*Checking intersection*/
        /*1st check sign of function beginnings*/
        double fValueIntersectionB =           f->value(intersection.first      );
        double fValueFirstB =                  f->value(first.first             );
        double fValueSecondB =                 f->value(second.first            );

        double fValueIntersectionE =           f->value(intersection.second     );
        double fValueFirstE =                  f->value(first.second            );
        double fValueSecondE =                 f->value(second.second           );

        double fDerivativeValueIntersectionB = f->derivValue(intersection.first );
        double fDerivativeValueFirstB =        f->derivValue(first.first        );
        double fDerivativeValueSecondB =       f->derivValue(second.first       );

        double fDerivativeValueIntersectionE = f->derivValue(intersection.second);
        double fDerivativeValueFirstE =        f->derivValue(first.second       );
        double fDerivativeValueSecondE =       f->derivValue(second.second      );

        if ((solver.sign(fValueIntersectionB) == solver.sign(fValueFirstB)) &&
            (solver.sign(fValueIntersectionB) == solver.sign(fValueSecondB)) &&
            (solver.sign(fValueIntersectionE) == solver.sign(fValueFirstE)) &&
            (solver.sign(fValueIntersectionE) == solver.sign(fValueSecondE)) &&
            (solver.sign(fDerivativeValueIntersectionB) ==
             solver.sign(fDerivativeValueFirstB)) &&
            (solver.sign(fDerivativeValueIntersectionB) ==
             solver.sign(fDerivativeValueSecondB)) &&
            (solver.sign(fDerivativeValueIntersectionE) ==
             solver.sign(fDerivativeValueFirstE)) &&
            (solver.sign(fDerivativeValueIntersectionE) ==
             solver.sign(fDerivativeValueSecondE))) {
          /*THIS IS TRUE INTERSECTION!!!!*/
          intervals[i] = intersection;
          intervals.erase(intervals.begin() + j);
          i = 0;
          j = 0;
        }
      }
    }
  }
  vector<pair<double, double>> result;
  for (int i = 0; i < (int)intervals.size(); i++) {
      result.push_back(make_pair(static_cast<double>(intervals[i].first),static_cast<double>(intervals[i].second)));
  }
  return result;
}
