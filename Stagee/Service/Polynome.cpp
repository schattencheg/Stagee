#include "Polynome.h"

Polynome::Polynome(vector<double> param) {
  int i = param.size();
  while ((i > 0) && (param[i] == 0.0)) i--;
  coeffs.insert(coeffs.begin(), param.begin(), param.begin() + i);
}

double Polynome::value(double x) const {
  double result = 0.0;
  for (unsigned int i = 0; i < coeffs.size(); i++) {
    result += coeffs[i] * pow(x, i);
  }
  return result;
}

double Polynome::decimalValue(double x) const {
    decimal<10> result(0.0);
    for (unsigned int i = 0; i < coeffs.size(); i++) {
      decimal<10> tmp(coeffs[i]*pow(x,i));
      result += tmp;
    }
    return result.getAsDouble();
}

double Polynome::derivValue(double x) const {
  double result = 0.0;
  //result = (value(x)        + value(       x + epsilon)) / epsilon;
  result =   (decimalValue(x) + decimalValue(x + epsilon)) / epsilon;
  return result;
}

bool Polynome::isDegenerative() const {
  bool result = true;
  for (unsigned int i = 0; i < coeffs.size(); i++) {
    if (coeffs[i] != 0.0) result = false;
  }
  return result;
}
