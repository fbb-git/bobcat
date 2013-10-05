inline bool SocketBase::setReuse(bool trueIsOn)
{
    return setBoolOption(SO_REUSEADDR, trueIsOn);
}
