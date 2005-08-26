#include "process.ih"

void Process::childRedirections()
{
    d_out->writtenBy(STDOUT_FILENO);
    d_err->writtenBy(STDERR_FILENO);
}
