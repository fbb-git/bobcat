#include "../primefactors/primefactors.hh"

void PrimeFactors::iteratorStream::next()
{
    BigInt candidate = d_lastPrime;

    do
    {
        resetPrimes();
        candidate += 2;
    }
    while (isComposite(candidate));

    if (d_newPrimes.size() == d_blockSize)
        writeNewPrimes();

    d_newPrimes.push_back(d_lastPrime = candidate);
}




