#include "errno.ih"

void Errno::open(std::fstream &stream, std::string const &name, 
                                    ios::openmode mode)
{
    if (stream.is_open())
        stream.close();

    stream.open(name.c_str(), mode);

    if (!stream)
        throw Errno(1) << "Can't open `" << name << '\'';
}
