#include "msg.ih"

void Msg::open(std::ifstream &in, std::string const &name)
{
    open(in, name, ios::in);
}
