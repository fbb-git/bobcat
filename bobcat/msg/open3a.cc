#include "msg.ih"

void Msg::open(ofstream &out, std::string const &name, size_t protection,
                                                    std::ios::openmode mode)
{
    close(creat(name.c_str(), protection));
    open(out, name, mode);
}
