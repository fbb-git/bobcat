#include "primefactors.ih"

void PrimeFactors::availablePrimes()
{
    const_iterator iter(*this);

    while (not d_value.isOne())
    {
        BigInt const &prime = *iter;        // get the next prime

        if (prime > d_last)                 // checked the last available 
        {
            if (not d_atSentinel)
            {
                d_factors.push_back({d_value, 1});
                d_value = 1;
            }
            break;
        }

        reduce(prime);                      // try to reduce d_value by prime

        ++iter;
    }
}



