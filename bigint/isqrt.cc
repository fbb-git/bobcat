#include "bigint.hh"

/*
    Newton's algorithm:

    x[i+1] = (x[i] + value / x[i]) / 2
    until convergence.
    the returned value is the biggest int `ret' for which ret * ret <= value

    With integral values the algorithm may be trapped in an endless loop where
    the next value exceeds the previous value (this happens, e.g., with  value
    = 15). This is handled by testing for this condition, rather than
    convergence.

    Initially x[0] = value
*/

BigInt &BigInt::isqrt()
{
    BigInt org(*this);
    BigInt tmp;

    BigInt *step = this;
    BigInt *next = &tmp;

    if (isZero() || isNegative())
        throw Exception(1) << "BigInt::isqrt: BigInt must be positive";

    while (true)
    {
        *next = *step + org / *step;
        next->rshift();

        if (*next >= *step)
            break;

        fswap(step, next);
    }

    if (this != step)
        *this = *step;

    return *this;
}

