inline std::ostream &operator<<(std::ostream &out, BigInt const &bn)
{
    return bn.insertInto(out);
}
