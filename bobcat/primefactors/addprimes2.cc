#include "primefactors.ih"

void PrimeFactors::addPrimes()
{
    BigInt prime(d_lastPrime);

    while (not d_value.isOne())
    {
        nextPrime(&prime);

        if (prime > d_last)             // beyond the last possible factor
        {
            d_factors.push_back({d_value, 1});
            break;
        }
 
       reduce(prime);
    }
}
