#ifndef ABSTRACTSOLVER_H
#define ABSTRACTSOLVER_H

#include <contdifffunction.h>
#include <vector>

using namespace std;

class AbstractSolver {
 public:
  AbstractSolver();
  virtual vector<double> solve(ContDiffFunction const *f, double left,
                               double right) = 0;
};

#endif  // ABSTRACTSOLVER_H
