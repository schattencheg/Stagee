#include "rootfinderstub.h"

RootFinderStub::RootFinderStub()
{

}

vector<double> RootFinderStub::findSignDiffPointsTransit(const ContDiffFunction *f, double left, double right)
{
    return findSignDiffPoints(f,left,right);
}

bool RootFinderStub::signTransit(double value)
{
    return sign(value);
}

vector<double> RootFinderStub::divByTwoTransit(const ContDiffFunction *f, double left, double right)
{
    return divByTwo(f,left,right);
}

bool RootFinderStub::isRootTransit(const ContDiffFunction *f, double value)
{
    return isRoot(f,value);
}
