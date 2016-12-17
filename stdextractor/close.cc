#include "stdextractor.ih"

void StdExtractor::close() // static
{
    ::close(STDIN_FILENO);  // close and reopen stdin
    ::open("/dev/null", O_RDONLY);
}
