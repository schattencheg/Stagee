#include "SolverNewtoneStub.h"

SolverNewtoneStub::SolverNewtoneStub()
{

}

vector<pair<double, double>> SolverNewtoneStub::findIntervalsTransit(const ContDiffFunction *f, double left, double right)
{
    return findIntervals(f,left,right);
}

bool SolverNewtoneStub::signTransit(double value)
{
    return sign(value);
}

vector<double> SolverNewtoneStub::intervalParseTransit(const ContDiffFunction *f, double left, double right)
{
    return intervalParse(f,make_pair(left,right));
}

bool SolverNewtoneStub::isRootTransit(const ContDiffFunction *f, double value)
{
    return isRoot(f,value);
}
