#ifndef FINDINTERVAL_H
#define FINDINTERVAL_H

#include <AbstractSolver.h>
#include <ContDiffFunction.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

class FindInterval {
 public:
  FindInterval();
  /*!
   * \brief findIntervals The method carries out search of the intervals which are potentially containing roots
   * \param f             Continuous differentiable function ContDiffFunction which roots we searching for
   * \param left          Left border of range of search of roots
   * \param right         Right border of range of search of roots
   * \param solver        The solving method, can be SolverDichotomy, SolverHorde, SolverNewtone
   * \return              Returns intervals i.e. couples [The left border, the Right border]
   */
  static vector<pair<double, double>> findIntervals(const ContDiffFunction *f,
                                                    double left,
                                                    double right,
                                                    AbstractSolver &solver);
};

#endif  // FINDINTERVAL_H
