/*!
 *   \defgroup Horde
 *   \ingroup AbstractSolver
 *   \brief Horde solver
 *
 *    Solve the equation by the horde method.
*/

#ifndef SolverHorde_H
#define SolverHorde_H

#include <AbstractSolver.h>
#include <FindInterval.h>
#include <cfloat>
#include <math.h>

class SolverHorde : public AbstractSolver {
 public:
  SolverHorde();
  /*!
   * \brief solve
   * \param f
   * \param left
   * \param right
   * \return
   */
  virtual vector<double> solve(ContDiffFunction const *f, double left,
                               double right);
 protected:
  /*!
   * \brief intervalParse
   * \param f
   * \param interval
   * \return
   */
  vector<double> intervalParse(const ContDiffFunction *f, pair<double,double> interval);
  /*!
   * \brief epsilon
   */
  double epsilon = 1e-15;      // Inaccuracy
  /*!
   * \brief distanceRoot
   */
  double distanceRoot = 0.01;  // Distance between two roots
};

#endif  // SolverHorde_H
