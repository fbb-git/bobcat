#include "extractorfork.ih"

void ExtractorFork::childRedirections()
{
    d_iChildOutPipe.writtenBy(STDOUT_FILENO);
}
