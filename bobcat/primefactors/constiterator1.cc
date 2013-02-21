#include "primefactors.ih"

PrimeFactors::const_iterator::const_iterator(PrimeFactors &primeFactors)
:
    d_primeFactors(primeFactors)
{
    d_primeFactors.iniRead();
    d_iterator = d_primeFactors.d_primes.begin();
}
