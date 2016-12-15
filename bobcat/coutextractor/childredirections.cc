#include "coutextractor.ih"

void CoutExtractor::childRedirections()
{
    (*d_modeFun)();             // optionally close STDIN and STDERR

    childOutPipe().writtenBy(STDOUT_FILENO);
}
