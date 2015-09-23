#include "../primefactors/primefactors.hh"

void PrimeFactors::iteratorStream::writeNewPrimes()
{
    d_stream.clear();
    d_stream.seekp(0, ios::end);

    copy(d_newPrimes.begin(), d_newPrimes.end(),
                              ostream_iterator<BigInt>(d_stream, "\n"));
    d_newPrimes.clear();
}
