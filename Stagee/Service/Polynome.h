#ifndef POLYNOMEBOOST_H
#define POLYNOMEBOOST_H

#include <ContDiffFunction.h>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <vector>
#include <math.h>

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
   * \brief value Value
   * \return      Returns value of function in param value point
   */
  virtual double value(double) const;
  /*!
   * \brief derivValue Derivative value
   * \return           Returns value of first derivative of function in param value point
   */
  virtual double derivValue(double) const;
  /*!
   * \brief isDegenerative Check if function is degenerative
   * \return 				Return true if function is degenerative (degenerate case is a limiting case in which an element
   *                        of a class of objects is qualitatively different from the rest of the class and hence belongs 
   *                        to another, usually simpler, class.)
   */
  virtual bool isDegenerative() const;
 protected:
  /*!
   * \brief epsilon Inaccuracy  at value of function, smaller this value is considered as a root
   */
  const cpp_bin_float_quad epsilon = 1e-5;
  /*!
   * \brief coeffs Vector of coefficients of polynome \f[f(x)=a_0 + a_1 x + a_2 x^2 + .. + a_{n-1} x^{n-1} + a_n x^n\f]
   */
  vector<double> coeffs;
};

#endif  // POLYNOMEBOOST_H
