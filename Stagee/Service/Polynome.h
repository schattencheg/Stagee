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
   * \return
   */
  virtual double value(double) const;
  /*!
   * \brief derivValue
   * \return
   */
  virtual double derivValue(double) const;
  /*!
   * \brief isDegenerative
   * \return
   */
  virtual bool isDegenerative() const;
 protected:
  /*!
   * \brief epsilon
   */
  const cpp_bin_float_quad epsilon = 1e-5;
  /*!
   * \brief coeffs
   */
  vector<double> coeffs;
};

#endif  // POLYNOMEBOOST_H
