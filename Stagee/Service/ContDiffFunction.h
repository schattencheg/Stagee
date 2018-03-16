#ifndef CONTDIFFFUNCTION_H
#define CONTDIFFFUNCTION_H

class ContDiffFunction {
 public:
  ContDiffFunction();
  /*!
   * \brief value
   * \return
   */
  virtual double value(double) const = 0;
  /*!
   * \brief derivValue
   * \return
   */
  virtual double derivValue(double) const = 0;
  /*!
   * \brief isDegenerative
   * \return
   */
  virtual bool isDegenerative() const = 0;
};

#endif  // CONTDIFFFUNCTION_H
