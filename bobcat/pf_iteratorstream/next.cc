#include "primefactors.ih"

void PrimeFactors::iterator::nextPrime(BigInt *prime)
{
    BigInt candidate = *prime;

    do
        candidate += 2;                 
    while (isComposite(candidate));

    d_newPrimes.push_back(candidate);
    if (d_newPrimes.size() == d_blockSize)
        writeNewPrimes();

    *prime = candidate;
}




