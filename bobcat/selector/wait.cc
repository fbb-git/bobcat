/*
                              selector.cc
*/

#include "selector.ih"

using namespace std;
using namespace FBB;


int Selector::wait() throw (Errno)
{
    timeval t = d_alarm;

    d_ret_read = d_read;
    d_ret_write = d_write;
    d_ret_except = d_except;

    d_readidx = 0;
    d_writeidx = 0;
    d_exceptidx = 0;

    d_ret = select(d_max, &d_ret_read, &d_ret_write, &d_ret_except, &t);

    if (d_ret < 0)
        throw Errno("Selector::wait()");
    
    return d_ret;
}
