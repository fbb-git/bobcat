inline BigInt &BigInt::operator+=(BigInt const &rhs)
{
    return checked1(BN_add, rhs, "+");
}
