inline BigInt &BigInt::subMod(BigInt const &rhs, BigInt const &mod)
{
    return checked2(BN_mod_sub, rhs, mod, "subMod");
}
