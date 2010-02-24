#include "gethostent.ih"

Errno GetHostent::hosterror(char const *text) 
{
    string msg = text;

    msg += ": ";
    switch (h_errno)
    {
        case HOST_NOT_FOUND:
            msg += "Unknown host";
        break;

        case TRY_AGAIN:
            msg += "Name server unreachable, try again later";
        break;

        case NO_RECOVERY:
            msg += "Unrecoverable error";
        break;

        case NO_ADDRESS:
            msg += "Missing address for hostname";
        break;
    }

    return Errno(h_errno, msg.c_str());
}


