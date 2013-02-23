#include "../primefactors/primefactors.ih"

bool PrimeFactors::iteratorStream::readPrimes()
{
    d_primes.clear();

    BigInt tmp;
    for (d_nAvailable = 0; d_nAvailable != d_blockSize; ++d_nAvailable)
    {
        if (not (d_stream >> tmp))
            break;
        d_primes.push_back(tmp);
    }

    setPrimesStatistics();

    return d_nAvailable;
}
