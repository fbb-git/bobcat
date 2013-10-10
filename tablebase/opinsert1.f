inline std::ostream &operator<<(std::ostream &str, TableBase &table)
{
    return table.insert(str);
}
