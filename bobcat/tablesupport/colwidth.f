inline size_t TableSupport::colWidth(size_t col) const
{
    return col < d_align->size() ? (*d_align)[col].col() : 0;
}
