#include "primefactors.ih"

bool PrimeFactors::sentinel()
{
    if (d_sentinel.isZero())
        return false;

    d_primes.clear();
    d_primes.push_back(d_sentinel);
    d_sentinel = 0;
    d_atSentinel = true;
    
    return true;
}
