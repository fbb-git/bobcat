#include "msg.ih"

void Msg::open(ofstream &out, std::string const &name, size_t protection)
{
    open(out, name, protection, ios::out);
}
