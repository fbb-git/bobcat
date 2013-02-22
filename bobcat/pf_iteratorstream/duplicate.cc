#include "../primefactors/primefactors.ih"

PrimeFactors::iterator *PrimeFactors::iteratorStream::duplicate() const
{
    return new iteratorStream(d_name, d_blockSize);
}
