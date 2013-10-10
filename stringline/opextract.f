inline std::istream &operator>>(std::istream &in, StringLine &str)
{
    return getline(in, str);
}
