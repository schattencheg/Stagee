#pragma GCC diagnostic ignored "-Wsign-compare"
#include "SolverDichotomy.h"

SolverDichotomy::SolverDichotomy() {}

vector<double> SolverDichotomy::solve(const ContDiffFunction *f, double left,
                                      double right) {
  if (f->isDegenerative()) {
    return vector<double>{};
  }
  vector<pair<double, double>> pointsOfInterest =
      findIntervals(f, left, right);
  vector<double> roots;
  for (unsigned int i = 0; i < pointsOfInterest.size(); i++) {
    vector<double> tempRoot =
        intervalParse(f, pointsOfInterest[i].first, pointsOfInterest[i].second);
    roots.insert(roots.end(), tempRoot.begin(), tempRoot.end());
  }
  return roots;
}

vector<pair<double, double>> SolverDichotomy::findIntervals(
    const ContDiffFunction *f, double left, double right) {
  srand(time(NULL));
  double d = 0.0001;  // Distance between two roots
  int maxIterationCount = 1000;
  double vMax = (right - left) / 10000;
  vector<double> values;
  /*Fills random sorted points*/
  int countToGenerate = (right - left) / d / 5000;
  for (int i = 0; i < countToGenerate; i++) {
    //double rndTmp = (double)rand() / RAND_MAX;
    //values.push_back(left + rndTmp * (right - left));
      double tmp = (left+i*(right-left)/countToGenerate);
      values.push_back(tmp);
  }
  sort(values.begin(), values.end());

  vector<pair<double, double>> intervals;

  /**/
  for (int i = 0; i < values.size(); i++) {
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
    while ((iteration < maxIterationCount) && (xNext <= right) &&
           (xNext >= left)) {
      f0 = f->value(xPrev);
      f1 = f->derivValue(xPrev);

      b0 = f0 >= 0 ? 1 : -1;
      b1 = f1 >= 0 ? 1 : -1;

      sNext = -b0 * b1;
      v = min(max(d, f0 / f1), vMax);
      xNext = xPrev + sNext * v;

      if (sNext * sPrev == -1) {
        /*We found it*/
        intervals.push_back(make_pair(min(xPrev, xNext), max(xPrev, xNext)));
        break;
      }
      sPrev = sNext;
      xPrev = xNext;
      iteration++;
    }
  }

  /*Combine intervals */
  for (int i = 0; i < intervals.size(); i++) {
    for (int j = i + 1; j < intervals.size(); j++) {
      // Checking this two intervals (i and j) is same
      //      i     [0,      1]
      //      j           [0,        1]
      pair<double, double> intersection;
      pair<double, double> first = intervals[i];
      pair<double, double> second = intervals[j];
      if ((first.first <= second.second + epsilon) && (first.second >= second.first - epsilon)) {
        intersection.first = min(first.first, second.first);
        intersection.second = max(first.second, second.second);
        /*Checking intersection*/
        /*1st check sign of function beginnings*/
        double fValueIntersectionB = f->value(intersection.first);
        double fValueFirstB = f->value(first.first);
        double fValueSecondB = f->value(second.first);

        double fValueIntersectionE = f->value(intersection.second);
        double fValueFirstE = f->value(first.second);
        double fValueSecondE = f->value(second.second);

        double fDerivativeValueIntersectionB =
            f->derivValue(intersection.first);
        double fDerivativeValueFirstB = f->derivValue(first.first);
        double fDerivativeValueSecondB = f->derivValue(second.first);

        double fDerivativeValueIntersectionE =
            f->derivValue(intersection.second);
        double fDerivativeValueFirstE = f->derivValue(first.second);
        double fDerivativeValueSecondE = f->derivValue(second.second);

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

  return intervals;
}

bool SolverDichotomy::sign(double value) {
  return (value >= -epsilon) ? true : false;
}

vector<double> SolverDichotomy::intervalParse(const ContDiffFunction *f, double left,
                                         double right) {
  double middle = (left + right) / 2.0;
  while ((!isRoot(f, middle)) || (left == middle) || (middle == right)) {
    double lft = f->value(left);
    double rgt = f->value(right);
    double mid = f->value(middle);

    if (sign(lft) != sign(mid)) {
      right = middle;
    } else if (sign(rgt) != sign(mid)) {
      left = middle;
    } else {
      break;
    }
    middle = (left + right) / 2.0;
  }
  vector<double> result;
  if (isRoot(f, middle)) result.push_back(middle);
  return result;
}

bool SolverDichotomy::isRoot(const ContDiffFunction *f, double value) {
  return (fabs(f->value(value)) < epsilon) ? true : false;
}
