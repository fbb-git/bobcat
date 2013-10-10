inline bool SocketBase::setDebug(bool trueIsOn)
{
    return setBoolOption(SO_DEBUG, trueIsOn);
}
