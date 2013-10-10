inline ReadLineHistory::HistoryElement const 
    *ReadLineHistory::const_iterator::operator->() const
{
    return &operator*();
}
