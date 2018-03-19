/*!
 *   \defgroup Dihotomy
 *   \ingroup AbstractSolver
 *   \brief Dihotomy solver
 *
 *    Solve the equation by the dichotomy method.
*/

#ifndef SOLVERDICHOTOMY_H
#define SOLVERDICHOTOMY_H_H

#include <AbstractSolver.h>
#include <FindInterval.h>
#include <cfloat>
#include <math.h>

class SolverDichotomy : public AbstractSolver {
 public:
  SolverDichotomy();
  /*!
   * \brief solve  Метод возвращает найденные корни функции f на диапазоне [left..right]
   * \param f      Функция ContDiffFunction, корни которой ищем
   * \param left   Левая граница диапазона поиска корней
   * \param right  Правая граница диапазона поиска корней
   * \return       Вектор найденных корней
   */
  virtual vector<double> solve(ContDiffFunction const *f,
                               double left,
                               double right);
 protected:
  /*!
   * \brief intervalParse Parsing an interval
   * \param f             Функция, которую парсим ContDiffFunction
   * \param interval      Интервал, заданный парой pair<double, double>
   * \return              Корень, если он есть на интервале
   */
  vector<double> intervalParse(const ContDiffFunction *f,
                               pair<double,double> interval);
  /*!
   * \brief epsilon - величина погрешности, при значении функции, меньшим этого значения считается корнем
   */
  double epsilon = 1e-15;      // Inaccuracy
  /*!
   * \brief distanceRoot - минимальное расстояние между корнями
   */
  double distanceRoot = 0.01;  // Distance between two roots
};

#endif  // SOLVERDICHOTOMY_H
