#include "../primefactors/primefactors.ih"

void PrimeFactors::iterator::next()
{
    do
        d_lastPrime += 2;                 
    while (isComposite());

    d_primes->push_back(d_lastPrime);
}




