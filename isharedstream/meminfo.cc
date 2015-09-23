#include "isharedstream.hh"

void ISharedStream::memInfo(std::ostream &out, char const *end) const
{
    static_cast<SharedStreambuf const *>(this)->memInfo(out);
    out << end;
}
