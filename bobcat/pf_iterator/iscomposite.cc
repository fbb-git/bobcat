#include "../primefactors/primefactors.ih"

bool PrimeFactors::iterator::isComposite()
{
    BigInt last(d_lastPrime.isqrtc());
    d_sentinel[0] = last + 1;

    while (*d_iterator <= last)
    {
        if ((d_lastPrime % *d_iterator).isZero())
            return true;

        ++d_iterator;
    }

    return false;
}
