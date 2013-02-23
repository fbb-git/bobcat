#include <iostream>

#include "primefactors"

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    vector<BigInt> primes;

//    PrimeFactors pf(primes);
    PrimeFactors pf("/tmp/primes");

//    PrimeFactors::Factors factors = pf.factorize(123456);
    PrimeFactors::Factors factors = pf.factorize(stoull(argv[1]));  // 123456);

    for (auto &factor: factors)
        cout << factor.prime << "**" << factor.power << ' ';

    cout << "\n"
            "Collected primes: ";

    for (auto &prime: primes)
        cout << prime << ' ';

    cout << '\n';
}    


