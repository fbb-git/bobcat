#include "execfork.ih"

void ExecFork::childRedirections()
{
    close(STDIN_FILENO);  // close and reopen std file descriptors
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    open("/dev/null", O_RDONLY);        // reopen stdin
    open("/dev/null", O_WRONLY);        // reopen cout
    open("/dev/null", O_WRONLY);        // reopen cerr
}
