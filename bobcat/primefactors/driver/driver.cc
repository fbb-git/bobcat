#include <iostream>
#include <bobcat/primefactors>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
{
    PrimeFactors pf1("/tmp/primes");
    PrimeFactors::Factors const *factors = &pf1.factorize(stoull(argv[1]));

    cout << "Using /tmp/primes:\n";
    for (auto &factor: *factors)
        cout << factor.prime << "**" << factor.power << ' ';

    vector<BigInt> primes;
    PrimeFactors pf2(primes);
    factors = &pf2.factorize(stoull(argv[1]));

    cout << "\n"
            "Using BigIntVector:\n";
    for (auto &factor: *factors)
        cout << factor.prime << "**" << factor.power << ' ';

    cout << "\n"
            "Collected primes: ";

    for (auto &prime: primes)
        cout << prime << ' ';

    cout << '\n';
}    


