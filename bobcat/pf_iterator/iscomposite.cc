#include "../primefactors/primefactors.ih"

bool PrimeFactors::iterator::isComposite()
{
    BigInt last(d_lastPrime.isqrtc());
    d_sentinel[0] = last + 1;

    iterator *iterPtr = clone();
    iterator &iter = *iterPtr;

    while (*iter <= last)
    {
        if ((d_lastPrime % *iter).isZero())
        {
            delete iterPtr;
            return true;
        }

        ++iter;
    }

    delete iterPtr;
    return false;
}
