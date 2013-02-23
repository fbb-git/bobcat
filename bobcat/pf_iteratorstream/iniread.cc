#include "../primefactors/primefactors.ih"

void PrimeFactors::iteratorStream::iniRead()
{
    d_stream.clear();
    d_stream.seekg(0);
    d_atSentinel = false;

    if (not nextLoad())
    {
        d_newPrimes = BigIntVector {2, 3};
        newPrimes();
    }
}
