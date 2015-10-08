#include "cidr.ih"

bool Cidr::compare(MaskPair const &mp, string const &address)
{
    size_t binary = dotted2binary(address);

                                // ~0: all 1s, 
                                // << moves in 0s over the masked bits
                                // ~() toggles 1s/0s
                                // | sets the masked bits to 1 in last.
    size_t last = mp.first | ~(~0 << (32 - mp.second));

    if (mp.first <= binary && binary <= last)
    {
        d_matched = address;
        d_last = last;
        return true;
    }

    return false;
}
