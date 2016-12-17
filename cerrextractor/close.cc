#include "cerrextractor.ih"

void CerrExtractor::close() // static
{
    ::close(STDIN_FILENO);  // close and reopen std file descriptors
    ::close(STDOUT_FILENO);

    ::open("/dev/null", O_RDONLY);        // reopen stdin
    ::open("/dev/null", O_WRONLY);        // reopen cout
}
