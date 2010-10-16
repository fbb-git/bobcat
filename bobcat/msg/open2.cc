#include "msg.ih"

void Msg::open(std::ofstream &out, std::string const &name)
{
    open(out, name, ios::out);
}
