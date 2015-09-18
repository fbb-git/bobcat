#include "gethostent.hh"

void GetHostent::hosterror(char const *text) 
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

    throw Exception(h_errno) << msg;
}


