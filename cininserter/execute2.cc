#include "cininserter.ih"

bool CinInserter::execute(string const &cmd, string const &txt)
{
    stop();

    d_oChildInPipe = Pipe{};

    Exec::execute(cmd);

    *this << txt;
    return stop() == 0;
}
