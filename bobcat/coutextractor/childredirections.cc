#include "coutextractor.ih"

void CoutExtractor::childRedirections()
{
    childOutPipe().writtenBy(STDOUT_FILENO);
}
