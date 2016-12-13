#include "extractorbase.ih"

bool ExtractorBase::execute(string const &cmd)
{
    d_iChildOutPipe = Pipe{};

    return Exec::execute(cmd);
}
