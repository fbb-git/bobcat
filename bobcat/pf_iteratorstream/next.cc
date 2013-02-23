#include "../primefactors/primefactors.ih"

void PrimeFactors::iteratorStream::next()
{
    BigInt candidate = d_lastPrime;

    do
    {
        iniRead();
        candidate += 2;
    }
    while (isComposite(candidate));

cerr << "next prime = " << candidate << '\n';

    d_primes.push_back(d_lastPrime = candidate);
    d_stream.clear();
    d_stream.seekp(0, ios::end);
    d_stream << candidate << endl;
}




