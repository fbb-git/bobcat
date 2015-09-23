#include "../primefactors/primefactors.hh"

void PrimeFactors::iterator::next()
{
    do
    {
        d_iterator = d_primes->begin();
        d_lastPrime += 2;
    }
    while (isComposite(d_lastPrime));

    d_primes->push_back(d_lastPrime);
}




