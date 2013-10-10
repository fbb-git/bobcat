inline TableBase::Element &TableBase::elementAt(size_t row, size_t col)
{
    return (this->*d_indexFun)(row, col);
}
