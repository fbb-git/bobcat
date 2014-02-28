inline std::istream &operator>>(std::istream &in, CSV &csv)
{
    return csv.extract(in);
}
