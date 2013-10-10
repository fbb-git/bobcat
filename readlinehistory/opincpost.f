inline ReadLineHistory::const_iterator 
    ReadLineHistory::const_iterator::operator++(int)
{
    return const_iterator(d_idx++);
}
