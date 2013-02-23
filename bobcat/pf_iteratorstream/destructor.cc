#include "../primefactors/primefactors.ih"

PrimeFactors::iteratorStream::~iteratorStream()
{
    cerr << "DESTRUCTOR CALLED\n";

    writeNewPrimes();
}
