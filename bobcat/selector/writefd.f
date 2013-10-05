inline int Selector::writeFd()
{               
    return checkSet(&d_writeidx, d_ret_write);
}
