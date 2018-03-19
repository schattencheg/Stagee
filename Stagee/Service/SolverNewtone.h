/*!
 *   \defgroup Newtone
 *   \ingroup AbstractSolver
 *   \brief Newtone solver
 *
 *    Solve the equation by the Newtone method.
*/

#ifndef SolverNewtone_H
#define SolverNewtone_H

#include <AbstractSolver.h>
#include <FindInterval.h>
#include <cfloat>
#include <math.h>

class SolverNewtone : public AbstractSolver {
 public:
  SolverNewtone();
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
   * \brief epsilon - величина погрешности, при значении функции, меньшим этого значения считается корнем
   */
  double epsilon = 1e-15;      // Inaccuracy
  /*!
   * \brief distanceRoot
   */
  double distanceRoot = 0.01;  // Distance between two roots
};

#endif  // SolverNewtone_H
