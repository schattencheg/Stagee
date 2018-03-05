/*#pragma GCC diagnostic ignored "-Wsign-compare"*/
#include "SolverDichotomy.h"

SolverDichotomy::SolverDichotomy() {}

vector<double> SolverDichotomy::solve(const ContDiffFunction *f,
                                           double left, double right) {
  if (f->isDegenerative()) {
    return vector<double>{};
  }
  vector<pair<double, double>> pointsOfInterest =
      findIntervals(f, left, right);
  vector<double> roots;
  for (unsigned int i = 0; i < pointsOfInterest.size(); i++) {
    vector<double> tempRoot = intervalParse(f, pointsOfInterest[i]);
    roots.insert(roots.end(), tempRoot.begin(), tempRoot.end());
  }
  return roots;
}

vector<pair<double, double>> SolverDichotomy::findIntervals(
    const ContDiffFunction *f, double left, double right) {
  srand(time(NULL));
  double d = 0.01;  // Distance between two roots
  int maxIterationCount = 1000;
  double vMax = (right - left) / 1000; //Highest Dx
  vector<double> values;
  /*Fills random, sorted points*/
  int countToGenerate = static_cast<int>((right - left) * 10 );
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
    double aValue = values[i];
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

      if (aValue>4.5)
          int tmp = 0;

      if (isRoot(f,xPrev)){intervals.push_back(make_pair(xPrev, xPrev)); break;}
      if (isRoot(f,xNext)){intervals.push_back(make_pair(xNext, xNext)); break;}

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
      if ((first.first <= second.second + epsilon) &&
          (first.second >= second.first - epsilon)) {
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

        if ((sign(fValueIntersectionB) == sign(fValueFirstB)) &&
            (sign(fValueIntersectionB) == sign(fValueSecondB)) &&
            (sign(fValueIntersectionE) == sign(fValueFirstE)) &&
            (sign(fValueIntersectionE) == sign(fValueSecondE)) &&
            (sign(fDerivativeValueIntersectionB) ==
             sign(fDerivativeValueFirstB)) &&
            (sign(fDerivativeValueIntersectionB) ==
             sign(fDerivativeValueSecondB)) &&
            (sign(fDerivativeValueIntersectionE) ==
             sign(fDerivativeValueFirstE)) &&
            (sign(fDerivativeValueIntersectionE) ==
             sign(fDerivativeValueSecondE))) {
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
  for (int i = 0; i < intervals.size(); i++) {
      result.push_back(make_pair(static_cast<double>(intervals[i].first),static_cast<double>(intervals[i].second)));
  }
  return result;
}

bool SolverDichotomy::sign(double value) {
  return (value >= 0) ? true : false;
}

bool SolverDichotomy::sign(cpp_bin_float_quad value) {
  return (value >= 0) ? true : false;
}

vector<double> SolverDichotomy::intervalParse(const ContDiffFunction *f,
                                              pair<double, double> interval) {
  double boundLeft = interval.first;
  double boundRight = interval.second;
  double boundMiddle = (boundLeft + boundRight) / 2.0;
  int iteration = 0;
  int maxIterationCount = 1000;
  while ((!isRoot(f, boundMiddle)) && (boundLeft != boundMiddle) && (boundMiddle != boundRight) && (iteration<maxIterationCount)) {
    double fValLft = f->value(boundLeft);
    double fValRgt = f->value(boundRight);
    double fValMid = f->value(boundMiddle);

    if (sign(fValLft) != sign(fValMid)) {
      boundRight = boundMiddle;
    } else if (sign(fValRgt) != sign(fValMid)) {
      boundLeft = boundMiddle;
    } else {
      //Lets try take interval with minimal value
      if (fValLft<fValRgt)boundRight=boundMiddle;
        else
          boundLeft=boundMiddle;
      //break;
    }
    boundMiddle = (boundLeft + boundRight) / 2.0;
    iteration++;
  }
  vector<double> result;
  if (isRoot(f, boundMiddle)) result.push_back(boundMiddle);
  return result;
}

bool SolverDichotomy::isRoot(const ContDiffFunction *f, double value) {
  return (fabs(f->value(value)) < epsilon) ? true : false;
}
