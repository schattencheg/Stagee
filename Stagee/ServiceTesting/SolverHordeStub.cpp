#include "SolverHordeStub.h"

SolverHordeStub::SolverHordeStub()
{

}

vector<pair<double, double>> SolverHordeStub::findIntervalsTransit(const ContDiffFunction *f, double left, double right)
{
    return FindInterval::findIntervals(f,left,right,*this);
}

bool SolverHordeStub::signTransit(double value)
{
    return sign(value);
}

vector<double> SolverHordeStub::intervalParseTransit(const ContDiffFunction *f, double left, double right)
{
    return intervalParse(f,make_pair(left,right));
}

bool SolverHordeStub::isRootTransit(const ContDiffFunction *f, double value)
{
    return isRoot(f,value);
}
