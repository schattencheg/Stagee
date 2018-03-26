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
  int maxIterationCount = 10000;
  int currentIteration = 0;
  double tmp1 = f->value(xL);
  double tmp2 = f->value(xR);
  while ((!isRoot(f, xR))&&(fabs(xR-xL)>=epsilon)&&(currentIteration < maxIterationCount))
  {
        //xL = xL - (xR-xL)*(f->value(xL)/(f->value(xR)-f->value(xL)));
        xL = xR - (xR-xL)*(f->value(xR)/(f->value(xR)-f->value(xL)));
        //xR = xR - (xL-xR)*(f->value(xR)/(f->value(xL)-f->value(xR)));
        xR = xL + (xL-xR)*(f->value(xL)/(f->value(xL)-f->value(xR)));
        currentIteration++;
  }
  vector<double> result;
  if (f->value(interval.first)*f->value(interval.second)<=0)
    result.push_back((fabs(f->value(xL))<fabs(f->value(xR)))?xL:xR);
  else
      if (isRoot(f,xR)) result.push_back(xR);
  return result;
}
