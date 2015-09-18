#include "primefactors.hh"

PrimeFactors::PrimeFactors(BigIntVector &primes)
:
    d_iterator(new iterator(primes))
{}


