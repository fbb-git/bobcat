#include "../primefactors/primefactors.hh"

void PrimeFactors::iteratorStream::resetPrimes()
{
    d_stream.clear();
    d_stream.seekg(0);
    d_mode = STREAM_PRIMES;

    readPrimes();
    
    if (not d_streamPrimes.empty())
        checkInitialPrimes(d_streamPrimes);
    else
    {
        d_mode = NEW_PRIMES;
        d_newPrimes = BigIntVector {2, 3};
        d_iterator = d_newPrimes.begin();
        d_lastPrime = 3;
    }
}
