#include "../primefactors/primefactors.ih"

bool PrimeFactors::iteratorStream::newPrimes()
{
    if (not d_newPrimes.empty())
    {
        d_primes = d_newPrimes;
        writeNewPrimes();

        d_iterator = d_primes.begin();
    }

    return not d_primes.empty();
}
