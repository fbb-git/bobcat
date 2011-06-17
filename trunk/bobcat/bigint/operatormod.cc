#include "bigint.ih"

namespace FBB
{

BigInt operator%(BigInt const &lhs, BigInt const &rhs)
{
    BigInt tmp(lhs);
    tmp %= rhs;
    return tmp;
}

}
