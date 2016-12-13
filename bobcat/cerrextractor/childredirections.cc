#include "cerrextractor.ih"

void CerrExtractor::childRedirections()
{
    childOutPipe().writtenBy(STDERR_FILENO);
}
