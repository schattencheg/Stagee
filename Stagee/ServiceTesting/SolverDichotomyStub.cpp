#include "SolverDichotomyStub.h"

SolverDichotomyStub::SolverDichotomyStub()
{

}

vector<pair<double, double>> SolverDichotomyStub::findIntervalsTransit(const ContDiffFunction *f, double left, double right)
{
    return FindInterval::findIntervals(f,left,right,*this);
}

bool SolverDichotomyStub::signTransit(double value)
{
    return sign(value);
}

vector<double> SolverDichotomyStub::intervalParseTransit(const ContDiffFunction *f, double left, double right)
{
    return intervalParse(f,make_pair(left,right));
}

bool SolverDichotomyStub::isRootTransit(const ContDiffFunction *f, double value)
{
    return isRoot(f,value);
}
