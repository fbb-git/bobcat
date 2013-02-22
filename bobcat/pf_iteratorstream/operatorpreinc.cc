#include "../primefactors/primefactors.ih"

PrimeFactors::iterator &PrimeFactors::iteratorStream::operatorPreInc()
{
    if (++d_iterator == d_primes.cend() && not nextLoad() && not newPrimes())
        sentinel();

    return *this;
}
