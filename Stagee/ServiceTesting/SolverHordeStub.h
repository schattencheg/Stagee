#ifndef SolverHordeSTUB_H
#define SolverHordeSTUB_H

#include <SolverHorde.h>

class SolverHordeStub : public SolverHorde
{
public:
    SolverHordeStub();
    vector<pair<double, double>> findIntervalsTransit(const ContDiffFunction *f, double left, double right);
    bool signTransit(double value);
    vector<double> intervalParseTransit(const ContDiffFunction *f, double left, double right);
    bool isRootTransit(const ContDiffFunction *f, double value);
};

#endif // SolverHordeSTUB_H
