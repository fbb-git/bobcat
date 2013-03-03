#include "primefactors.ih"

void PrimeFactors::reduce(BigInt const &prime)
{
    BigInt remainder;
    size_t count = 0;

    while (true)
    {
        BigInt div(d_value.divc(&remainder, prime));
        if (not remainder.isZero())
            break;

        d_value = div;
        ++count;
    }

    if (count)
        d_factors.push_back({prime, count});
}
