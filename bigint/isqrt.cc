#include "bigint.ih"

/*
    Newton's algorithm:

    x[i+1] = (x[i] + value / x[i]) / 2
    until convergence.
    the returned value is the biggest int `ret' for which ret * ret <= value
*/

BigInt &BigInt::isqrt()
{
    BigInt org(*this);
    BigInt tmp;

    BigInt *step = this;
    BigInt *next = &tmp;

    while (*this != tmp)
    {
        *next = *step + org / *step;
        next->rshift();
        fswap(step, next);
    }

    return *this;
}

