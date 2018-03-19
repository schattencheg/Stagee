#ifndef CONTDIFFFUNCTION_H
#define CONTDIFFFUNCTION_H

class ContDiffFunction {
 public:
  ContDiffFunction();
  /*!
   * \brief value Value
   * \return Returns value of function in param value point
   */
  virtual double value(double) const = 0;
  /*!
   * \brief derivValue Derivative value
   * \return Returns value of first derivative of function in param value point
   */
  virtual double derivValue(double) const = 0;
  /*!
   * \brief isDegenerative Check if function is degenerative
   * \return Return true if function is degenerative (degenerate case is a limiting case in which an element
   * of a class of objects is qualitatively different from the rest of the class and hence belongs to another, usually simpler, class.)
   */
  virtual bool isDegenerative() const = 0;
};

#endif  // CONTDIFFFUNCTION_H
