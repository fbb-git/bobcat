#include "cininserter.ih"

bool CinInserter::execute(string const &cmd)
{
    d_oChildInPipe = Pipe{};

    return Exec::execute(cmd);
}
