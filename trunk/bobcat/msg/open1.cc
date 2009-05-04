#include "msg.ih"

void Msg::open(std::ifstream &in, std::string const &name)
{
    if (access(name.c_str(), R_OK) != 0)
        msg() << "Can't read `" << name << "'" << fatal;

    in.open(name.c_str());
}
