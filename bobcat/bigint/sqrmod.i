inline BigInt &BigInt::sqrMod(BigInt const &mod)
{
    return checked4(BN_mod_sqr, mod, "sqrMod");
}
