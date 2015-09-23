#include "../primefactors/primefactors.hh"

PrimeFactors::iterator::iterator(BigIntVector &primes)
:
    d_mode(PRIMES),
    d_primes(&primes),
    d_sentinel(1)
{
    if (primes.empty())
        primes = BigIntVector{2, 3};

    d_lastPrime = primes.back();
    d_iterator = primes.begin();
}
