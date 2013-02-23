#include "primefactors.ih"

void PrimeFactors::addPrimes()
{
    BigInt const &prime = d_iterator->lastPrime();

    cerr << "add primes, last = " << prime << ", value = " << d_value << "\n";

    while (not d_value.isOne())
    {
        d_iterator->nextPrime();
cerr << "next new prime = " << prime << '\n';

        if (prime > d_last)             // beyond the last possible factor
        {
            d_factors.push_back({d_value, 1});
            break;
        }
        reduce(prime);
    }
}
