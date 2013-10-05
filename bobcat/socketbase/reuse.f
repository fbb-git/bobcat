inline bool SocketBase::reuse() const
{
    return boolOption(SO_REUSEADDR);
}
