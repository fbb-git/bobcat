#include "selector.ih"

int Selector::wait()
{
    timeval t = d_alarm;

    d_ret_read = d_read;
    d_ret_write = d_write;
    d_ret_except = d_except;

    d_readidx = 0;
    d_writeidx = 0;
    d_exceptidx = 0;

    d_ret = select(d_max, &d_ret_read, &d_ret_write, &d_ret_except, 
                   t.tv_sec == -1 && t.tv_usec == -1 ? 0 : &t);

    if (d_ret < 0)
        throw Exception() << "Selector::wait()";
    
    return d_ret;
}



