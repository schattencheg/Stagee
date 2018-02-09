#ifndef ROOTFINDERSTUB_H
#define ROOTFINDERSTUB_H

#include <RootFinder.h>

class RootFinderStub : public RootFinder
{
public:
    RootFinderStub();
    vector<double> findSignDiffPointsTransit(const ContDiffFunction *f, double left, double right);
    bool signTransit(double value);
    vector<double> divByTwoTransit(const ContDiffFunction *f, double left, double right);
    bool isRootTransit(const ContDiffFunction *f, double value);
};

#endif // ROOTFINDERSTUB_H
