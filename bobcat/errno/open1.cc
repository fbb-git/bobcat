#include "errno.ih"

void Errno::open(std::ifstream &in, std::string const &name,
                                        std::ios::openmode mode)
{
    if (in.is_open())
        in.close();

    in.open(name.c_str(), mode);

    if (!in)
        throw Errno(1) << "Can't read `" << name << '\'';
}
