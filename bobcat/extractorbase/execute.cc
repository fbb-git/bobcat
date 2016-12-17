#include "extractorbase.ih"

void ExtractorBase::execute(string const &cmd)
{
    d_iChildOutPipe = Pipe{};

    Exec::execute(cmd);
}
