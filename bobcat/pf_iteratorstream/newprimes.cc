#include "../primefactors/primefactors.ih"

bool PrimeFactors::iteratorStream::newPrimes()
{
    if (d_newPrimes.empty())
        return false;

    d_primes = d_newPrimes;

    if (d_newPrimes.size() == d_blockSize)
        writeNewPrimes();

    d_iterator = d_primes.begin();

    return true;
}
