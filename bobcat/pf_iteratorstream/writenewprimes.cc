#include "../primefactors/primefactors.ih"

void PrimeFactors::iteratorStream::writeNewPrimes()
{
    if (d_newPrimes.empty())
        return;

    // cerr << "adding " << d_newPrimes.size() << " new primes\n";

    d_stream.clear();
    d_stream.seekp(0, ios::end);

    copy(d_newPrimes.begin(), d_newPrimes.end(),
         ostream_iterator<BigInt>(d_stream, "\n"));

    d_newPrimes.clear();
}
