#include "exception.ih"

Exception::Exception(int errnoValue)
{
    errno = errnoValue;
}
