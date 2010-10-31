#include "bigint.ih"

namespace FBB
{

BigInt const operator<<(BigInt const &lhs, size_t nBits)
{
    BigInt tmp(lhs);
    tmp <<= nBits;
    return tmp;
}

}
