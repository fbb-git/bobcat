#include "fork.ih"

void Fork::fork()
{
    if ((d_pid = ::fork()) < 0)
        throw Exception() << "Fork::fork()";

    if (d_pid == 0)         // childprocess has pid == 0
    {
        childRedirections();
        childProcess();

        throw Exception(1); // we shouldn't come here: childProcess should
                            // exit
    }

    parentRedirections();
    parentProcess();
}
