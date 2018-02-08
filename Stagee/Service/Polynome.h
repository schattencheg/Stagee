#ifndef POLYNOME_H
#define POLYNOME_H

#include <contdifffunction.h>
#include <vector>
#include <math.h>
using namespace std;

class Polynome : public ContDiffFunction {
 public:
  Polynome(vector<double> param);
  virtual double value(double) const;
  virtual double derivValue(double) const;
  bool isDegenerative();

 protected:
  const double epsilon = 1e-8;
  vector<double> coeffs;
};

#endif  // POLYNOME_H
