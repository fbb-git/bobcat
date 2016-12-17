#include "cininserter.ih"

void CinInserter::stdClose() // static
{
    ::close(STDOUT_FILENO);  // close and reopen std file descriptors
    ::close(STDERR_FILENO);

    ::open("/dev/null", O_RDONLY);        // reopen stdout
    ::open("/dev/null", O_WRONLY);        // reopen stderr
}
