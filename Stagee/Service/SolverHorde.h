#ifndef SolverHorde_H
#define SolverHorde_H

#include <AbstractSolver.h>
#include <cfloat>
#include <math.h>
#include <boost/multiprecision/cpp_bin_float.hpp>
using namespace boost::multiprecision;
typedef cpp_bin_float_quad boostFloat;

class SolverHorde : public AbstractSolver {
 public:
  SolverHorde();
  virtual vector<double> solve(ContDiffFunction const *f, double left,
                               double right);

 protected:
  const double epsilon = 1e-15;
  vector<pair<double, double> > findIntervals(const ContDiffFunction *f, double left, double right);
  bool sign(double value);
  bool sign(cpp_bin_float_quad value);
  vector<double> intervalParse(const ContDiffFunction *f, pair<double,double> interval);
  bool isRoot(const ContDiffFunction *f, double value);
  bool isRoot(const ContDiffFunction *f, cpp_bin_float_quad value);

};

#endif  // SolverHorde_H
