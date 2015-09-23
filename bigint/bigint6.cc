#include "bigint.hh"

BigInt::BigInt(string const &bigEndian, bool negative)
:
    BigInt(bigEndian.data(), bigEndian.length(), negative)
{}
