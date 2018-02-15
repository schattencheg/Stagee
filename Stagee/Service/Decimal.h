#ifndef DECIMAL_H
#define DECIMAL_H

#include <math.h>
#include <stdint.h>
#include <string.h>

using namespace std;

class Decimal {
 public:
  Decimal(double value);
  Decimal(long int int_part, unsigned long int float_part);
  Decimal(Decimal& value);

  Decimal &operator +(Decimal& right);
  Decimal &operator -(Decimal &right);
  Decimal &operator *(Decimal &right);
  Decimal &operator /(Decimal &right);
  void print(char* s);
protected:
  long int m_int;
  uint64_t m_float;
  void normalize();
};

#endif  // DECIMAL_H
