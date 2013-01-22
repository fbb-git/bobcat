#include "exception.ih"

namespace FBB
{

std::ostream &errnodescr(std::ostream &out)
{
    if (errno != 0)
    {
        char *buffer = new char[Exception::STRERROR_BUFSIZE];

        if (char *cp = strerror_r(errno, buffer, Exception::STRERROR_BUFSIZE))
            out << cp;
        else
        {
            out << "internal error: strerror_r failed with errno = " << errno;
        }

        delete[] buffer;
    }

    return out;
}

} // FBB
