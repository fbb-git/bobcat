#include "../primefactors/primefactors.ih"

PrimeFactors::iterator *PrimeFactors::iterator::duplicate() const
{
    return new iterator(*d_primes);
}
