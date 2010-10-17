#include "msg.ih"

void Msg::open(std::fstream &out, std::string const &name, ios::openmode mode)
{
    out.open(name.c_str(), mode);

    if (!out)
        msg() << "Can't open `" << name << '\'' << fatal;
}
