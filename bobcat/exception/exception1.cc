#include "exception.ih"

Exception::Exception(int errnoValue)
{
    g_errno = errno = errnoValue;
}
