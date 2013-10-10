inline ReadLineHistory::const_iterator 
    &ReadLineHistory::const_iterator::operator++()
{
    ++d_idx;
    return *this;
}
