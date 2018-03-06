#ifndef SolverNewtoneSTUB_H
#define SolverNewtoneSTUB_H

#include <SolverNewtone.h>

class SolverNewtoneStub : public SolverNewtone
{
public:
    SolverNewtoneStub();
    vector<pair<double, double>> findIntervalsTransit(const ContDiffFunction *f, double left, double right);
    bool signTransit(double value);
    vector<double> intervalParseTransit(const ContDiffFunction *f, double left, double right);
    bool isRootTransit(const ContDiffFunction *f, double value);
};

#endif // SolverNewtoneSTUB_H
