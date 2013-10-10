template <typename Type>    // Insert any other insertable type into a Table
Table &operator<<(Table &table, Type const &ref)
{
    reinterpret_cast<std::ostringstream &>(table) << ref;
    return table.flush();
}
