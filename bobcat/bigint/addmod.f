inline BigInt &BigInt::addMod(BigInt const &rhs, BigInt const &mod)
{
    return checked2(BN_mod_add, rhs, mod, "addMod");
}
