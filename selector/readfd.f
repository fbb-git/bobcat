inline int Selector::readFd()
{
    return checkSet(&d_readidx, d_ret_read);
}
