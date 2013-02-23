#include "../primefactors/primefactors.ih"

void PrimeFactors::iteratorStream::setPrimesStatistics()
{
    if (d_primes.size())
        d_lastPrime = d_primes.back();

    d_iterator = d_primes.begin();
}
