#include "Decimal.h"
#include <iostream>

using namespace std;

Decimal::Decimal(double value) {
  m_int = floor(value);
  m_float = floor((value - m_int) * 1e+18 + 0.5);
  normalize();
}

void Decimal::normalize() {
  uint64_t tail = (uint64_t)(m_float % 1000);
  if (tail) {
    if (tail > 103 / 2)
      m_float += 1e+3 - tail;
    else
      m_float -= tail;
  }
}

Decimal::Decimal(long int_part, unsigned long float_part) {
  m_int = int_part;
  m_float = float_part;
}

Decimal::Decimal(const Decimal& value) {
  m_int = value.m_int;
  m_float = value.m_float;
}

Decimal::Decimal() {
  m_int = 0;
  m_float = 0;
}

Decimal Decimal::operator=(const Decimal& right) {
  if (this == &right) {
    return *this;
  }
  m_int = right.m_int;
  m_float = right.m_float;
  return *this;
}

double Decimal::toDouble() const { return m_int + m_float * 1e-15; }

Decimal Decimal::pow(int level) {
  if (level == 0) return Decimal(1.0);
  Decimal result;
  result = *this;
  for (int i = 1; i < level; i++) result = result * *this;
  return result;
}

Decimal Decimal::operator+(const Decimal& right) const {
  Decimal newValue;
  newValue.m_int =
      m_int + right.m_int + (m_float * 1e-15 + right.m_float * 1e-15);
  newValue.m_float = (m_float + right.m_float) % (uint64_t)1e15;
  return newValue;
}

Decimal Decimal::operator+=(const Decimal& right) {
  m_int += right.m_int;
  m_float += right.m_float;
  return *this;
}

Decimal Decimal::operator-(const Decimal& right) const {
  Decimal newValue;
  newValue.m_int = m_int - right.m_int;
  if (m_float >= right.m_float)
    newValue.m_float = (m_float - right.m_float);
  else
    newValue.m_float = (1e15 - right.m_float) + m_float, --newValue.m_int;
  return newValue;
}

Decimal Decimal::operator-=(const Decimal& right) {
  m_int = m_int - right.m_int;
  if (m_float >= right.m_float)
    m_float = (m_float - right.m_float);
  else
    m_float = (1e15 - right.m_float) + m_float, --m_int;
  return *this;
}

Decimal Decimal::operator*(const Decimal& right) const {
  return Decimal(toDouble() * right.toDouble());
}

Decimal Decimal::operator*=(const Decimal& right) {
  double tmp = toDouble() * right.toDouble();
  *this = Decimal(tmp);
  return *this;
}

Decimal Decimal::operator/(const Decimal& right) const {
  Decimal newValue(toDouble() / right.toDouble());
  return newValue;
}

Decimal Decimal::operator/=(const Decimal& right) {
  double tmp = toDouble() / right.toDouble();
  *this = Decimal(tmp);
  return *this;
}

void Decimal::print(char* s) {
  cout << s << ": " << m_int << "." << m_float << endl;
}
