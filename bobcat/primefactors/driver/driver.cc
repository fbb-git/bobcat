#include <iostream>

#include "primefactors"

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    PrimeFactors primeFactors("/tmp/primes");

    PrimeFactors::Factors factors = primeFactors.factorize(stoull(argv[1]));

    for (auto factor: factors)
        cout << factor.prime << "**" << factor.count << ' ';
    cout << '\n';
}    
