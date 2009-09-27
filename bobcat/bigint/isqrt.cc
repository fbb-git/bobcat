#include "bigint.ih"

/*
    Newton's algorithm:

    x[i+1] = (x[i] + value / x[i]) / 2
    until convergence.
    the returned value is the biggest int `ret' for which ret * ret <= value
*/

BigInt const BigInt::isqrt() const
{
    BigInt ret1(*this);
    BigInt ret2;

    BigInt *step = &ret1;
    BigInt *next = &ret2;

    while (ret1 != ret2)
    {
        *next = *step + *this / *step;
        next->rshift();
        swap(step, next);
    }

    return ret1;
}

