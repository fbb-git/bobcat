#include "exception.hh"

Exception::Exception(int errnoValue)
{
    errno = errnoValue;
}
