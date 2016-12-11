#include "extractorfork.ih"

bool ExtractorFork::execute(string const &cmd)
{
    d_iChildOutPipe = Pipe{};

    return ExecFork::execute(cmd);
}
