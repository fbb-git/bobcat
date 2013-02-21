#include "primefactors.ih"

PrimeFactors::const_iterator &PrimeFactors::const_iterator::operator++()
{
    d_primeFactors.increment(d_iterator);
    return *this;
}
