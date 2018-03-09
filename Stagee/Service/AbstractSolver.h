#ifndef ABSTRACTSOLVER_H
#define ABSTRACTSOLVER_H

#include <ContDiffFunction.h>
#include <vector>
#include <math.h>

using namespace std;

class AbstractSolver {
 public:
  AbstractSolver();
  virtual vector<double> solve(ContDiffFunction const *f, double left,
                               double right) = 0;
  bool sign(double value);
  bool isRoot(const ContDiffFunction *f, double value);
  double epsilon = 1e-15;      // Inaccuracy
  double distanceRoot = 0.01;  // Distance between two roots
};

#endif  // ABSTRACTSOLVER_H
