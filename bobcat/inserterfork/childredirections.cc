#include "inserterfork.ih"

void InserterFork::childRedirections()
{
    int fd = ::open("/dev/null", O_WRONLY);

    Redirector redirector(fd);
    redirector.swallow(Redirector::STDERR);

    d_oChildInPipe.readFrom(STDIN_FILENO);
}
