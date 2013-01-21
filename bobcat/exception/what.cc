#include "exception.ih"

char const *Exception::what() const noexcept(true)
{
    return d_what.c_str();
}
