#include "../primefactors/primefactors.ih"

void PrimeFactors::iteratorStream::iniRead()
{
    d_stream.clear();
    d_stream.seekg(0);
    d_atSentinel = false;
    d_nAvailable = 0;

    readPrimes();

    if (not d_primes.empty())
        checkInitialPrimes(d_primes);
    else
    {
        d_primes = BigIntVector {2, 3};
        setPrimesStatistics();

        d_stream.clear();
        d_stream.seekp(0, ios::end);
        d_stream << 2 << '\n' << 3 << endl;

    }
}
