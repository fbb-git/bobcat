#include "bigint.hh"

namespace FBB
{

BigInt operator<<(BigInt const &lhs, size_t nBits)
{
    BigInt tmp(lhs);
    tmp <<= nBits;
    return tmp;
}

}
