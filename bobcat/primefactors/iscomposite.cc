#include "primefactors.ih"

bool PrimeFactors::isComposite(BigInt const &candidate)
{
    BigInt last(candidate.isqrtc());
    d_sentinel = last + 1;

    const_iterator iter(*this);

    while (*iter <= last)
    {
        if ((candidate % *iter).isZero())
            return true;

        ++iter;
    }

    return false;
}
