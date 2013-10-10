inline size_t TableSupport::sepWidth(size_t col) const
{
    return col < d_sep.size() ? d_sep[col].length() : 0;
}
