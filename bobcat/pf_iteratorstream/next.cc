#include "../primefactors/primefactors.ih"

void PrimeFactors::iteratorStream::next()
{
    do
        d_lastPrime += 2;                 
    while (isComposite());

    d_newPrimes.push_back(d_lastPrime);

    if (d_newPrimes.size() == d_blockSize)
        writeNewPrimes();
}




