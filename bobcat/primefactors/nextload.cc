#include "primefactors.ih"

bool PrimeFactors::nextLoad()
{
    d_primes.clear();

    BigInt tmp;
    size_t idx = 0;
    for ( ; idx != d_blockSize; ++idx)
    {
        if (not (d_stream >> tmp))
            break;
        d_primes.push_back(tmp);
    }

    if (d_primes.size())
    {
        d_lastPrime = d_primes.back();
        return true;
    }
    return false;
}


