/*
                              errno.cc
*/

#include "errno.ih"

char const *Errno::what() const
{
    return (d_what = d_msg + str()).c_str();
}
