#include "../primefactors/primefactors.ih"

PrimeFactors::iterator &PrimeFactors::iterator::operatorPreInc()
{
    if (++d_iterator == d_primes->cend())
        sentinel();

    return *this;
}
