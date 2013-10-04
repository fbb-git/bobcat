inline TableSupport::ColumnType operator|(TableSupport::ColumnType lhs,
                                          TableSupport::ColumnType rhs)
{
    return static_cast<TableSupport::ColumnType>(
                    static_cast<int>(lhs) | static_cast<int>(rhs));
}
