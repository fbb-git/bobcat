#include <iostream>

#include "primefactors"

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    vector<BigInt> primes;

    PrimeFactors primeFactors(primes);

    PrimeFactors::Factors factors = primeFactors.factorize(stoull(argv[1]));

    for (auto factor: factors)
        cout << factor.prime << "**" << factor.power << ' ';
    cout << '\n';
}    
