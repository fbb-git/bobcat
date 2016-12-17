#include "stdextractor.ih"

namespace
{
    int stdFds[] =
    {
        STDOUT_FILENO,
        STDERR_FILENO
    };
}

void StdExtractor::childRedirections()
{
    (*d_modeFun)();             // optionally close STDIN

    childOutPipe().writtenBy(stdFds, 2);
}
