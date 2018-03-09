#pragma GCC diagnostic ignored "-Wsign-compare"
#include "SolverHorde.h"

SolverHorde::SolverHorde() {}

vector<double> SolverHorde::solve(const ContDiffFunction *f, double left,
                                  double right) {
  if (f->isDegenerative()) {
    return vector<double>{};
  }
  vector<pair<double, double>> pointsOfInterest = FindInterval::findIntervals(f, left, right, *this);
  vector<double> roots;
  for (unsigned int i = 0; i < pointsOfInterest.size(); i++) {
    vector<double> tempRoot = intervalParse(f, pointsOfInterest[i]);
    roots.insert(roots.end(), tempRoot.begin(), tempRoot.end());
  }
  return roots;
}

vector<double> SolverHorde::intervalParse(const ContDiffFunction *f,
                                          pair<double, double> interval) {
  double xL = interval.first;
  double xR = interval.second;
  while (fabs(xR-xL)>=epsilon)
  {
      xL = xL - (xR-xL)*(f->value(xL)/(f->value(xR)-f->value(xL)));
      xR = xR - (xL-xR)*(f->value(xR)/(f->value(xL)-f->value(xR)));
  }

  vector<double> result;
  if (isRoot(f, xR)) result.push_back(xR);
  return result;
}
