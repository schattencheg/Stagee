#ifndef SolverDichotomySTUB_H
#define SolverDichotomySTUB_H

#include <SolverDichotomy.h>

class SolverDichotomyStub : public SolverDichotomy
{
public:
    SolverDichotomyStub();
    vector<pair<double, double>> findIntervalsTransit(const ContDiffFunction *f, double left, double right);
    bool signTransit(double value);
    vector<double> intervalParseTransit(const ContDiffFunction *f, double left, double right);
    bool isRootTransit(const ContDiffFunction *f, double value);
};

#endif // SolverDichotomySTUB_H
