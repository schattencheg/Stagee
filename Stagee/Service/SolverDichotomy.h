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
   * \brief solve  ����� ���������� ��������� ����� ������� f �� ��������� [left..right]
   * \param f      ������� ContDiffFunction, ����� ������� ����
   * \param left   ����� ������� ��������� ������ ������
   * \param right  ������ ������� ��������� ������ ������
   * \return       ������ ��������� ������
   */
  virtual vector<double> solve(ContDiffFunction const *f,
                               double left,
                               double right);
 protected:
  /*!
   * \brief intervalParse Parsing an interval
   * \param f             �������, ������� ������ ContDiffFunction
   * \param interval      ��������, �������� ����� pair<double, double>
   * \return              ������, ���� �� ���� �� ���������
   */
  vector<double> intervalParse(const ContDiffFunction *f,
                               pair<double,double> interval);
  /*!
   * \brief epsilon - �������� �����������, ��� �������� �������, ������� ����� �������� ��������� ������
   */
  double epsilon = 1e-15;      // Inaccuracy
  /*!
   * \brief distanceRoot - ����������� ���������� ����� �������
   */
  double distanceRoot = 0.01;  // Distance between two roots
};

#endif  // SOLVERDICHOTOMY_H
