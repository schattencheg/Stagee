#ifndef CONTDIFFFUNCTION_H
#define CONTDIFFFUNCTION_H

class ContDiffFunction {
 public:
  ContDiffFunction();
  virtual double value(double) const = 0;
  virtual double derivValue(double) const = 0;
  virtual bool isDegenerative() const = 0;
};

#endif  // CONTDIFFFUNCTION_H
