inline Table &operator<<(Table &table, Table &(*fun)(Table &))
{
    return (*fun)(table);
}
