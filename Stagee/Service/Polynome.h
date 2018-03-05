#ifndef POLYNOMEBOOST_H
#define POLYNOMEBOOST_H

#include <ContDiffFunction.h>
#include <vector>
#include <math.h>
#include <boost/multiprecision/cpp_bin_float.hpp>
using namespace boost::multiprecision;
using namespace std;

class Polynome : public ContDiffFunction {
 public:
  Polynome(vector<double> param);
  virtual double value(double) const;
  virtual double derivValue(double) const;
  virtual bool isDegenerative() const;
 protected:
  const cpp_bin_float_quad epsilon = 1e-5;
  vector<double> coeffs;
  cpp_bin_float_quad pOw(cpp_bin_float_quad x, int level) const;
};

#endif  // POLYNOMEBOOST_H
