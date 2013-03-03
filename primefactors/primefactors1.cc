#include "primefactors.ih"

PrimeFactors::PrimeFactors(BigIntVector &primes)
:
    d_iterator(new iterator(primes))
{}


