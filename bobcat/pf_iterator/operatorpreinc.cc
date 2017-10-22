#include "../primefactors/primefactors.ih"

PrimeFactors::iterator &PrimeFactors::iterator::operatorPreInc()
{
    ++d_iterator;

    switch (d_mode)
    {
        case PRIMES:
            if (d_iterator != d_primes->cend())
                break;
            d_mode = SENTINEL;
            d_iterator = d_sentinel.begin();
        [[fallthrough]]

        case SENTINEL:
        break;
    }

    return *this;
}
