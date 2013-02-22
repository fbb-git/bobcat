#include "primefactors.ih"

PrimeFactors::PrimeFactors(string const &name, size_t blockSize)
:
    d_iterator(iteratorStream(name, blockSize))
{}

