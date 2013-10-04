inline 
TableSupport::const_iterator &TableSupport::const_iterator::operator++()
{
    ++d_iter;
    return *this;
}
