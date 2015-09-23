#include "primefactors.hh"

void PrimeFactors::availablePrimes()
{
    while (not d_value.isOne())
    {
        BigInt const &prime = **d_iterator; // get the next prime

        if (prime > d_last)                 // checked the last available 
        {
            if (not d_iterator->atSentinel())
            {
                d_factors.push_back({d_value, 1});
                d_value = 1;
            }
            return;
        }

        reduce(prime);                      // try to reduce d_value by prime

        ++*d_iterator;
    }
}



