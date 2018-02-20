#ifndef POLYNOME_H
#define POLYNOME_H

#include <ContDiffFunction.h>
#include <vector>
#include <math.h>
#include <decimal_.h>

using namespace dec;
using namespace std;

class Polynome : public ContDiffFunction {
 public:
  Polynome(vector<double> param);
  virtual double value(double) const;
  virtual double derivValue(double) const;
  virtual bool isDegenerative() const;
  virtual double decimalValue(double x) const;
 protected:
  const double epsilon = 1e-8;
  vector<double> coeffs;
};

#endif  // POLYNOME_H
