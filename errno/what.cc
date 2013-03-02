/*
                              errno.cc
*/

#include "errno.ih"

char const *Errno::what() const throw()     // required by std. exception hdr
{
    return (d_what = d_msg + str()).c_str();
}
