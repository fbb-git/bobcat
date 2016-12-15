#include "cerrextractor.ih"

void CerrExtractor::childRedirections()
{
    (*d_modeFun)();             // optionally close STDIN and STDOUT

    childOutPipe().writtenBy(STDERR_FILENO);
}
