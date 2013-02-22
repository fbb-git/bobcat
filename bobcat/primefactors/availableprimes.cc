#include "primefactors.ih"

void PrimeFactors::availablePrimes()
{
    while (not d_value.isOne())
    {

        BigInt const &prime = **d_iterator; // get the next prime

cerr << "prime = " << prime << ", last = " << d_last << ", value = " <<
d_value << '\n';

        if (prime > d_last)                 // checked the last available 
        {
            if (not d_iterator->atSentinel())
            {
                d_factors.push_back({d_value, 1});
                d_value = 1;
            }
            break;
        }

        reduce(prime);                      // try to reduce d_value by prime

        ++*d_iterator;
    }
}



