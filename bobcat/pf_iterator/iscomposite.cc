#include "../primefactors/primefactors.ih"

bool PrimeFactors::iterator::isComposite(BigInt const &candidate)
{
    BigInt last(candidate.isqrtc());
    d_sentinel[0] = last + 1;

    while (*d_iterator <= last)
    {
        if ((candidate % *d_iterator).isZero())
            return true;

        ++d_iterator;
    }

    return false;
}
