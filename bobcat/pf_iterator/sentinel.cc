#include "../primefactors/primefactors.ih"

void PrimeFactors::iterator::sentinel()
{
    cerr << "sentinel = " << d_sentinel[0] << '\n';

    if (not d_sentinel[0].isZero())
    {
        d_atSentinel = true;
        d_iterator = d_sentinel.begin();
    }
}
