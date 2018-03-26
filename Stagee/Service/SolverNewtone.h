/*!
 *   \defgroup Newtone
 *   \ingroup  AbstractSolver
 *   \brief    Newtone solver
 *
 *    Solve the equation by the Newtone method.
*/

#ifndef SOLVERNEWTONE_H
#define SOLVERNEWTONE_H

#include <AbstractSolver.h>
#include <FindInterval.h>
#include <cfloat>
#include <math.h>

class SolverNewtone : public AbstractSolver {
 public:
  SolverNewtone();
  /*!
   * \brief solve The method returns found roots of the function f on the range [left..right]
   * \param f     Continuous differentiable function ContDiffFunction which roots we searching for
   * \param left  Left border of range of search of roots
   * \param right Right border of range of search of roots
   * \return      Vector of the found roots
   */
  virtual vector<double> solve(ContDiffFunction const *f, double left,
                               double right);
 protected:
  /*!
   * \brief intervalParse Parsing an interval
   * \param f             Function ContDiffFunction which we parse
   * \param interval      The interval set by couple of pair pair<double, double>
   * \return              Root if it is on an interval else blanc
   */
  vector<double> intervalParse(const ContDiffFunction *f, pair<double,double> interval);
  /*!
   * \brief epsilon Inaccuracy  at value of function, smaller this value is considered as a root
   */
  double epsilon = 1e-12;
  /*!
   * \brief distanceRoot Minimum distance between roots
   */
  double distanceRoot = 0.01;
};

#endif  // SOLVERNEWTONE_H
