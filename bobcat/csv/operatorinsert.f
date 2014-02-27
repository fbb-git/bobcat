inline std::ostream &operator<<(std::ostream &out, CSV const &csv)
{
    return (csv.*csv.d_insert)(out);
}
