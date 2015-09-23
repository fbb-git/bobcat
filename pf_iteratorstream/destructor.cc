#include "../primefactors/primefactors.hh"

PrimeFactors::iteratorStream::~iteratorStream()
{
    writeNewPrimes();
}
