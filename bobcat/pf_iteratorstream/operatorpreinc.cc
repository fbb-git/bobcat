#include "../primefactors/primefactors.ih"

PrimeFactors::iterator &PrimeFactors::iteratorStream::operatorPreInc()
{
    if (++d_iterator == d_primes.cend() && not readPrimes())
        sentinel();

    return *this;
}
