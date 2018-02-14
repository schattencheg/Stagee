#include "SolverNewtone.h"

SolverNewtone::SolverNewtone() {}

vector<double> SolverNewtone::solve(const ContDiffFunction *f, double left,
                                 double right) {
  if (f->isDegenerative()) { return vector<double>{}; }
  vector<double> pointsOfInterest = findSignDiffPoints(f, left, right);
  vector<double> roots;
  for (unsigned int i = 0; i < pointsOfInterest.size() - 1; i++) {
    vector<double> tempRoot =
        divByTwo(f, pointsOfInterest[i], pointsOfInterest[i + 1]);
    roots.insert(roots.end(), tempRoot.begin(), tempRoot.end());
  }
  return roots;
}

vector<double> SolverNewtone::findSignDiffPoints(const ContDiffFunction *f,
                                              double left, double right) {
  double step = 0.001;
  double cur = f->derivValue(left);
  double tmp = f->derivValue(left);

  vector<double> values;
  values.push_back(left);
  for (double x = left + step; x < right; x += step) {
    cur = f->derivValue(x);
    if (cur*tmp<=0.0) {
      values.push_back(x);
      values.push_back(x + step);
    }
    tmp = cur;
  }
  values.push_back(right);
  return values;
}

bool SolverNewtone::sign(double value) { return (value >= 0.0) ? true : false; }

vector<double> SolverNewtone::divByTwo(const ContDiffFunction *f, double left,
                                    double right) {
  double middle = (left + right) / 2.0;
  while (!isRoot(f, middle)) {
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

bool SolverNewtone::isRoot(const ContDiffFunction *f, double value) {
  return (fabs(f->value(value)) < epsilon) ? true : false;
}