#ifndef SOLVERDICHOTOMY_H
#define SOLVERDICHOTOMY_H_H

#include <AbstractSolver.h>
#include <cfloat>
#include <math.h>

class SolverDichotomy : public AbstractSolver {
 public:
  SolverDichotomy();
  virtual vector<double> solve(ContDiffFunction const *f, double left,
                               double right);

 protected:
  const double epsilon = 1e-8;
  vector<double> findSignDiffPoints(const ContDiffFunction *f, double left, double right);
  bool sign(double value);
  vector<double> divByTwo(const ContDiffFunction *f, double left, double right);
  bool isRoot(const ContDiffFunction *f, double value);
};

#endif  // SOLVERDICHOTOMY_H
