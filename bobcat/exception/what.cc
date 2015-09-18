#include "exception.hh"

char const *Exception::what() const noexcept(true)
{
    return d_what.c_str();
}
