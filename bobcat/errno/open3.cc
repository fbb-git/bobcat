#include "errno.ih"

void Errno::open(std::ofstream &out, std::string const &name, 
                                                size_t protection)
{
    close(creat(name.c_str(), protection));
    open(out, name);
}
