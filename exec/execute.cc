#include "exec.ih"

bool Exec::execute(std::string const &cmd)
{
    d_cmd = cmd;
    fork();
    return d_ret == 0;
}
