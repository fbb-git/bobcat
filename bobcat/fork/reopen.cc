#include "fork.hh"

void Fork::reopen(string const &out, mode_t mode)
{
    if (out.empty())
        open("/dev/null", O_RDONLY);        // reopen stdout
    else if (open(out.c_str(), O_CREAT | O_APPEND | O_WRONLY, mode) == -1)
        throw Exception() << "Cannot open " << out << ": " << errnodescr;
}
