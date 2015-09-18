#include "bigint.hh"

namespace FBB
{

ostream &operator<<(ostream &out, BigInt::Bit const &bit)
{
    return out << (bit.d_bi.hasBit(bit.d_idx) ? '1' : '0');
}

}
