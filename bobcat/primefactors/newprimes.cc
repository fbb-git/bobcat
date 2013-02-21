#include "primefactors.ih"

bool PrimeFactors::newPrimes()
{
    if (d_newPrimes.size())
    {
        d_primes = d_newPrimes;
        d_newPrimes.clear();

        d_stream.clear();
        d_stream.seekp(0, ios::end);

        copy(d_primes.begin(), d_primes.end(), 
            ostream_iterator<BigInt>(d_stream, "\n"));
    }

    return d_primes.size();
}
