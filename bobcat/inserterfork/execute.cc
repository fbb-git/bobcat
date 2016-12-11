#include "inserterfork.ih"

bool InserterFork::execute(string const &cmd)
{
    d_oChildInPipe = Pipe{};

    return ExecFork::execute(cmd);
}
