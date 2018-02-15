#ifndef DECIMAL_H
#define DECIMAL_H

#include <math.h>

class Decimal {
 public:
  Decimal(double value);
  Decimal(long int int_part, unsigned long int float_part);
  //Decimal(Decimal value);

  friend const Decimal operator+(const Decimal& left, const Decimal& right) {
        Decimal newValue(0.0);
        newValue.m_int = left.m_int + right.m_int + (left.m_float+right.m_float)*1e-18;
        newValue.m_float = (left.m_float*1e-18 + right.m_float*1e-18)*1e18;
        return newValue;
      }

 protected:
  long int m_int;
  unsigned long int m_float;
};

#endif  // DECIMAL_H
