#include "cininserter.ih"

void CinInserter::execute(string const &cmd)
{
    stop();                         // stop any previously running child

    d_oChildInPipe = Pipe{};
    Exec::execute(cmd);

    d_stopped = false;
}
