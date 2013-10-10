inline int Selector::exceptFd()
{                
    return checkSet(&d_exceptidx, d_ret_except);
}
