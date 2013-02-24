#include "../primefactors/primefactors.ih"

bool PrimeFactors::iteratorStream::readPrimes()
{
    d_streamPrimes.clear();

    BigInt tmp;
    size_t idx;
    for (idx = 0; idx != d_blockSize; ++idx)
    {
        if (not (d_stream >> tmp))
            break;
        d_streamPrimes.push_back(tmp);
    }

    if (idx != 0)
        d_lastPrime = d_streamPrimes.back();

    d_iterator = d_streamPrimes.begin();

    return idx;
}
