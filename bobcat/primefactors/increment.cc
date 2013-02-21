#include "primefactors.ih"

void PrimeFactors::increment(ConstIterator &iterator)
{
    if 
    (
        ++iterator == d_primes.cend()
        &&
        (nextLoad() || newPrimes() || sentinel())
    )
        iterator = d_primes.begin();
}
