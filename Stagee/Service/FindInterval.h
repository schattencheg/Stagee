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
   * \brief findIntervals .Функция осуществляет поиск интервалов, потенциально содержащих корни
   * \param f             .Функция ContDiffFunction, корни которой ищем
   * \param left          .Левая граница интервала
   * \param right         .Правая граница интервала
   * \param solver        .Метод решения, может быть SolverDichotomy, SolverHorde, SolverNewtone
   * \return              .Возвращает интервалы, парами [Левая граница, Правая граница]
   */
  static vector<pair<double, double>> findIntervals(const ContDiffFunction *f,
                                                    double left,
                                                    double right,
                                                    AbstractSolver &solver);
};

#endif  // FINDINTERVAL_H
