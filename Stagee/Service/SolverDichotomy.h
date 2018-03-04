#ifndef SOLVERDICHOTOMY_H
#define SOLVERDICHOTOMY_H_H

#include <AbstractSolver.h>
#include <cfloat>
#include <math.h>
/*vector sort*/
#include <algorithm>
/*random stuff*/
#include <time.h>
#include <stdlib.h>
/*cout*/
#include <iostream>
using namespace std;

class SolverDichotomy : public AbstractSolver {
 public:
  SolverDichotomy();
  virtual vector<double> solve(ContDiffFunction const *f, double left,
                               double right);

 protected:
  const double epsilon = 1e-8;
  vector<pair<double, double> > findIntervals(const ContDiffFunction *f, double left, double right);
  bool sign(double value);
  vector<double> intervalParse(const ContDiffFunction *f, double left, double right);
  bool isRoot(const ContDiffFunction *f, double value);
};

#endif  // SOLVERDICHOTOMY_H
