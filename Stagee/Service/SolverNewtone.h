#ifndef SolverNewtone_H
#define SolverNewtone_H

#include <AbstractSolver.h>
#include <cfloat>
#include <math.h>

class SolverNewtone : public AbstractSolver {
 public:
  SolverNewtone();
  virtual vector<double> solve(ContDiffFunction const *f, double left,
                               double right);

 protected:
  const double epsilon = 1e-8;
  vector<double> findSignDiffPoints(const ContDiffFunction *f, double left, double right);
  bool sign(double value);
  vector<double> divByTwo(const ContDiffFunction *f, double left, double right);
  bool isRoot(const ContDiffFunction *f, double value);
};

#endif  // SolverNewtone_H
