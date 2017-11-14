template <typename Type>
inline Exception operator<<(Exception &&tmp, Type const &value)
{
    std::ostringstream out;
    out << value;
    tmp.d_what += out.str();

    return std::move(tmp);
}
