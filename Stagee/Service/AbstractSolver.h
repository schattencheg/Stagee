/*!
 *   \defgroup AbstractSolver
 *   \brief Abstract class for solvers
 *
 *   Provide unified interface for different methods of solving equations.
*/

#ifndef ABSTRACTSOLVER_H
#define ABSTRACTSOLVER_H

#include <ContDiffFunction.h>
#include <vector>
#include <math.h>

using namespace std;

class AbstractSolver {
 public:
  AbstractSolver();

  /*!
   * \brief solve method returns vector of equation's roots and taking three arguments
   * \param f an ContDiffFunction (continuously differentiable function)
   * \param left an left border from which we need to find roots
   * \param right an right border to which we need to find roots
   * \return vector of roots
   */
  virtual vector<double> solve(ContDiffFunction const *f, double left,
                               double right) = 0;
  /*!
   * \brief sign method determines which sign of a number
   * \param value an double value
   * \return
   */
  bool sign(double value);
  /*!
   * \brief isRoot determines if number is a root of function
   * \param f function
   * \param value number to check
   * \return
   */
  bool isRoot(const ContDiffFunction *f, double value);
  /*!
   * \brief epsilon Inaccuracy  at value of function, smaller this value is considered as a root
   */
  double epsilon = 1e-15;
  /*!
   * \brief distanceRoot Minimum distance between roots
   */
  double distanceRoot = 0.01;
};

#endif  // ABSTRACTSOLVER_H
