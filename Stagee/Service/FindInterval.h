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
   * \brief findIntervals
   * \param f
   * \param left
   * \param right
   * \param solver
   * \return
   */
  static vector<pair<double, double>> findIntervals(const ContDiffFunction *f,
                                                    double left, double right,
                                                    AbstractSolver &solver);
};

#endif  // FINDINTERVAL_H
