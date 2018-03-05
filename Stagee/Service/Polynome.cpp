#include "Polynome.h"

Polynome::Polynome(vector<double> param) {
  int i = param.size();
  while ((i > 0) && (param[i] == 0.0)) i--;
  coeffs.insert(coeffs.begin(), param.begin(), param.begin() + i);
}

cpp_bin_float_quad Polynome::pOw(cpp_bin_float_quad x, int level) const
{
    cpp_bin_float_quad result = 1;
    for (int i = 0; i < level; i++)
    {
        result *= x;
    }
    return result;
}

double Polynome::value(double x) const {
  cpp_bin_float_quad result = 0.0;
  cpp_bin_float_quad X = x;
  for (unsigned int i = 0; i < coeffs.size(); i++) {
    //result = result + pOw(X, i) * coeffs[i];
    result = result + boost::multiprecision::pow(X, i) * coeffs[i];
  }
  return static_cast<double>(result);
}

double Polynome::derivValue(double x) const {
  cpp_bin_float_quad result = 0.0;
  cpp_bin_float_quad first = value(static_cast<double>(epsilon+x));
  double tempFirst = static_cast<double>(first);
  cpp_bin_float_quad second = value(x);
  double tempSecond = static_cast<double>(second);
  result = (first - second) / epsilon;
  double tempResult = static_cast<double>(result);
  return static_cast<double>(result);
}

bool Polynome::isDegenerative() const {
  bool result = true;
  for (unsigned int i = 0; i < coeffs.size(); i++) {
    if (coeffs[i] != 0.0) result = false;
  }
  return result;
}

