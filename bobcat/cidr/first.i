inline std::string Cidr::first() const
{
    return binary2dotted(d_iter->first);
}
