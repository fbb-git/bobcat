#include "primefactors.ih"

PrimeFactors::PrimeFactors(string const &name, size_t blockSize)
:
    d_stream(name, ios::in | ios::out)
{
    if (not d_stream)
    {
        d_stream.clear();
        Exception::open(d_stream, name, ios::out | ios::trunc | ios::in);
        d_stream.seekp(0);
        d_stream << 2 << '\n' << 3 << endl;
    }
    d_primes.reserve(blockSize);
}
