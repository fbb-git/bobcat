#include "../primefactors/primefactors.ih"

PrimeFactors::iteratorStream::~iteratorStream()
{
    writeNewPrimes();
}
