#include "csv.ih"

size_t CSV::count() const
{
    return std::count(d_available.begin(), d_available.end(), true);
}
