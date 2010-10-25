#include "errno.ih"

void Errno::open(std::ofstream &out, std::string const &name,
                ios::openmode mode)
{
    out.open(name.c_str(), mode);

    if (!out)
        throw Errno(1) << "Can't write `" << name << '\'';
}
