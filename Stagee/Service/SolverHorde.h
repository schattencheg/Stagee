#ifndef SolverHorde_H
#define SolverHorde_H

#include <AbstractSolver.h>
#include <cfloat>
#include <math.h>

class SolverHorde : public AbstractSolver {
 public:
  SolverHorde();
  virtual vector<double> solve(ContDiffFunction const *f, double left,
                               double right);

 protected:
  const double epsilon = 1e-8;
  vector<double> findSignDiffPoints(const ContDiffFunction *f, double left, double right);
  bool sign(double value);
  vector<double> divByTwo(const ContDiffFunction *f, double left, double right);
  bool isRoot(const ContDiffFunction *f, double value);
};

#endif  // SolverHorde_H
