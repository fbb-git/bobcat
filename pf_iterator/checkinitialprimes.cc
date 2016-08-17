#include "../primefactors/primefactors.ih"

void PrimeFactors::iterator::checkInitialPrimes(
                                        BigIntVector const &primes) const
{
    if (primes.size() < 2 || primes[0] != 2 || primes[1] != 3)
        throw Exception{} << "PrimeFactors: first primes must be 2 and 3";
}

