#include "msg.ih"

void Msg::open(std::ifstream &in, std::string const &name, ios::openmode mode)
{
    if (access(name.c_str(), R_OK) != 0)
        throw Errno(1) << "Can't read `" << name << '\'';

    in.open(name.c_str(), mode);
}
