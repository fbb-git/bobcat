#include "primefactors.ih"

PrimeFactors::PrimeFactors(string const &name, size_t blockSize)
:
    d_iterator(new iteratorStream(name, blockSize))
{}

