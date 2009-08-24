#include "bigint.ih"

namespace FBB
{

BigInt const operator+(BigInt const &lhs, BigInt const &rhs)
{
    BigInt tmp(lhs);
    tmp += rhs;
    return tmp;
}

}
