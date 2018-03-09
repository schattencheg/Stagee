#ifndef SolverNewtone_H
#define SolverNewtone_H

#include <AbstractSolver.h>
#include <FindInterval.h>
#include <cfloat>
#include <math.h>

class SolverNewtone : public AbstractSolver {
 public:
  SolverNewtone();
  virtual vector<double> solve(ContDiffFunction const *f, double left,
                               double right);
 protected:
  vector<double> intervalParse(const ContDiffFunction *f, pair<double,double> interval);
  double epsilon = 1e-15;      // Inaccuracy
  double distanceRoot = 0.01;  // Distance between two roots
};

#endif  // SolverNewtone_H
