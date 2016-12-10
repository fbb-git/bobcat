#include "execfork.ih"

bool ExecFork::execute(std::string const &cmd)
{
    d_cmd = cmd;
    fork();
    return d_ret == 0;
}
