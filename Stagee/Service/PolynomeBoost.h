#ifndef POLYNOMEBOOST_H
#define POLYNOMEBOOST_H

#include <ContDiffFunction.h>
#include <vector>
#include <math.h>
#include <boost/multiprecision/cpp_bin_float.hpp>
using namespace boost::multiprecision;
using namespace std;

class PolynomeBoost : public ContDiffFunction {
 public:
  PolynomeBoost(vector<double> param);
  virtual double value(double) const;
  virtual double derivValue(double) const;
  virtual bool isDegenerative() const;
 protected:
  const cpp_bin_float_quad epsilon = 1e-8;
  vector<double> coeffs;
};

#endif  // POLYNOMEBOOST_H
