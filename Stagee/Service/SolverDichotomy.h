#ifndef SOLVERDICHOTOMY_H
#define SOLVERDICHOTOMY_H_H

#include <AbstractSolver.h>
#include <cfloat>
#include <math.h>
#include <boost/multiprecision/cpp_bin_float.hpp>
using namespace boost::multiprecision;
typedef cpp_bin_float_quad boostFloat;

class SolverDichotomy : public AbstractSolver {
 public:
  SolverDichotomy();
  virtual vector<double> solve(ContDiffFunction const *f, double left,
                               double right);

 protected:
  const double epsilon = 1e-15;
  const double distanceRoot = 0.01;  // Distance between two roots
  vector<pair<double, double> > findIntervals(const ContDiffFunction *f, double left, double right);
  bool sign(double value);
  bool sign(cpp_bin_float_quad value);
  vector<double> intervalParse(const ContDiffFunction *f, pair<double,double> interval);
  bool isRoot(const ContDiffFunction *f, double value);
  bool isRoot(const ContDiffFunction *f, cpp_bin_float_quad value);
};

#endif  // SOLVERDICHOTOMY_H
