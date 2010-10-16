#include "msg.ih"

void Msg::open(std::ofstream &out, std::string const &name, ios::openmode mode)
{
    out.open(name.c_str(), mode);

    if (!out)
        msg() << "Can't write `" << name << "'" << fatal;
}
