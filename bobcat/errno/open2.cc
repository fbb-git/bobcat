#include "errno.ih"

void Errno::open(std::ofstream &out, std::string const &name,
                ios::openmode mode)
{
    if (out.is_open())
        out.close();

    out.open(name.c_str(), mode);

    if (!out)
        throw Errno(1) << "Can't write `" << name << '\'';
}
