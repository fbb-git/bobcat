inline std::string Cidr::mask() const
{
    return to_string(d_iter->second);   // X2a
}
