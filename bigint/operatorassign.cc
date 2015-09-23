#include "bigint.hh"

BigInt &BigInt::operator=(BigInt const &other)
{
    BigInt tmp(other);
    swap(tmp);

    return *this;
}
