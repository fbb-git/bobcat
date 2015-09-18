#include "../primefactors/primefactors.hh"

PrimeFactors::iterator &PrimeFactors::iteratorStream::operatorPreInc()
{
    ++d_iterator;

    switch (d_mode)
    {
        case STREAM_PRIMES:
            if (d_iterator != d_streamPrimes.cend())
                break;

            readPrimes();
            if (d_iterator != d_streamPrimes.cend())
                break;

            d_mode = NEW_PRIMES;
            d_iterator = d_newPrimes.begin();
        // FALLING THROUGH
        
        case NEW_PRIMES:
            if (d_iterator != d_newPrimes.cend())
                break;

            d_mode = SENTINEL;
            d_iterator = d_sentinel.begin();
        // FALLING THROUGH

        case SENTINEL:
        break;
    }

    return *this;
}



