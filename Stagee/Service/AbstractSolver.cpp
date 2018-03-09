#include "AbstractSolver.h"

AbstractSolver::AbstractSolver() {}

bool AbstractSolver::sign(double value) {
  return (value >= 0) ? true : false;
}

bool AbstractSolver::isRoot(const ContDiffFunction *f, double value) {
  return (fabs(f->value(value)) < epsilon) ? true : false;
}

