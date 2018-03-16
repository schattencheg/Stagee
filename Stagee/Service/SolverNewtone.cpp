#include "SolverNewtone.h"

SolverNewtone::SolverNewtone() {}

vector<double> SolverNewtone::solve(const ContDiffFunction *f, double left,
                                    double right) {
  if (f->isDegenerative()) {
    return vector<double>{};
  }
  vector<pair<double, double>> pointsOfInterest = FindInterval::findIntervals(f, left, right,*this);
  vector<double> roots;
  for (unsigned int i = 0; i < pointsOfInterest.size(); i++) {
    vector<double> tempRoot = intervalParse(f, pointsOfInterest[i]);
    roots.insert(roots.end(), tempRoot.begin(), tempRoot.end());
  }
  return roots;
}

vector<double> SolverNewtone::intervalParse(const ContDiffFunction *f,
                                            pair<double, double> interval) {
  double xN = (interval.first + interval.second) / 2.0;
  while ((!isRoot(f, xN)) && (xN <= interval.second) &&
         (xN >= interval.first)) {
    xN = xN - f->value(xN) / f->derivValue(xN);
  }
  vector<double> result;
  if (isRoot(f, xN)) result.push_back(xN);
  return result;
}
