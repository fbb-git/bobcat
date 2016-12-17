#include "coutextractor.ih"

void CoutExtractor::close() // static
{
    ::close(STDIN_FILENO);  // close and reopen std file descriptors
    ::close(STDERR_FILENO);

    ::open("/dev/null", O_RDONLY);        // reopen stdin
    ::open("/dev/null", O_WRONLY);        // reopen stderr
}
