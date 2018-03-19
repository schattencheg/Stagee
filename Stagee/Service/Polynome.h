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
    /*!
   * \brief Polynome
   * \param param
   */
  Polynome(vector<double> param);
  /*!
   * \brief value
   * \return �������� ������� � �����, �������� ����������.
   */
  virtual double value(double) const;
  /*!
   * \brief derivValue
   * \return �������� ������ ����������� ������� � �����, �������� ����������.
   */
  virtual double derivValue(double) const;
  /*!
   * \brief isDegenerative
   * \return ���������� TRUE ���� ������� ����������� (�������� ������� ���������� �������)
   */
  virtual bool isDegenerative() const;
 protected:
  /*!
   * \brief epsilon - �������� �����������, ��� f(x)<epsilon x ��������� ������ f(x)
   */
  const cpp_bin_float_quad epsilon = 1e-5;
  /*!
   * \brief coeffs - ������ ������������� ��� �������� x. \f[f(x)=a_0 + a_1 x + a_2 x^2 + .. + a_{n-1} x^{n-1} + a_n x^n\f]
   */
  vector<double> coeffs;
};

#endif  // POLYNOMEBOOST_H
