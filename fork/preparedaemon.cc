#include "fork.ih"

void Fork::prepareDaemon() const
{
    if (chdir("/") < 0)     // free up mount points
        throw Exception() << "Fork::prepareDaemon: chdir(\"/\") failed\n";

    setsid();               // create new session/process group

    ::close(STDIN_FILENO);  // close and reopen std file descriptors
    ::close(STDOUT_FILENO);
    ::close(STDERR_FILENO);

    open("/dev/null", O_RDONLY);        // reopen stdin
    open("/dev/null", O_WRONLY);        // reopen cout
    open("/dev/null", O_WRONLY);        // reopen cerr
}
