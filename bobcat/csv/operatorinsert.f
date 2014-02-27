inline std::ostream &operator<<(std::ostream &in, CSV const &csv)
{
    return csv.insert(in);
}
