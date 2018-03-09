#pragma GCC diagnostic ignored "-Wsign-compare"
#include "SolverDichotomy.h"

SolverDichotomy::SolverDichotomy() {}

vector<double> SolverDichotomy::solve(const ContDiffFunction *f,
                                           double left, double right) {
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
