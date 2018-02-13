#include "SolverDichotomyStub.h"

SolverDichotomyStub::SolverDichotomyStub()
{

}

vector<double> SolverDichotomyStub::findSignDiffPointsTransit(const ContDiffFunction *f, double left, double right)
{
    return findSignDiffPoints(f,left,right);
}

bool SolverDichotomyStub::signTransit(double value)
{
    return sign(value);
}

vector<double> SolverDichotomyStub::divByTwoTransit(const ContDiffFunction *f, double left, double right)
{
    return divByTwo(f,left,right);
}

bool SolverDichotomyStub::isRootTransit(const ContDiffFunction *f, double value)
{
    return isRoot(f,value);
}
