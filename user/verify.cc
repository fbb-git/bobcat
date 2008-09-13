#include "user.ih"

void User::verify() const
{
    if (d_msg)
        throw Errno(1, d_msg);
}

        
