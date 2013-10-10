inline char const * const *Hostent::endAlias() const
{
    return h_aliases + nAliases();
}
