#include "../primefactors/primefactors.ih"

PrimeFactors::iteratorStream::iteratorStream(std::string const &name, 
                                              size_t blockSize)
:
    d_name(name),
    d_blockSize(blockSize)
{
    openStream();
    d_primes.reserve(blockSize);

    iniRead();
}

