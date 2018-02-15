#include "Decimal.h"

Decimal::Decimal(double value)
{
    m_int = floor(value);
    m_float = (value - m_int) * 1e18;
}

Decimal::Decimal(long int_part, unsigned long float_part)
{
    m_int = int_part;
    m_float = float_part;
}

//Decimal::Decimal(Decimal value)
//{
//    m_int = value.m_int;
//    m_float = value.m_float;
//}
