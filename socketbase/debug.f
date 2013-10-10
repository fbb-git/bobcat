inline bool SocketBase::debug() const
{
    return boolOption(SO_DEBUG);
}
