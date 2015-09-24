#include "process.ih"

void Process::childRedirections()
{
    if (d_mode & CIN)                               // CHILD PROCESS:
        d_oChildInPipe.readFrom(STDIN_FILENO);        //  reads from the pipe

    if (d_mode & MERGE_COUT_CERR)             //  cout/cerr to 1 pipe
    {
        int fd[] = {STDOUT_FILENO, STDERR_FILENO};
        d_iChildOutPipe.writtenBy(fd, 2);
    }
    else
    {
        if (d_mode & COUT)                          //  cout to a pipe
            d_iChildOutPipe.writtenBy(STDOUT_FILENO);

        if (d_mode & CERR)                          //  cerr to another pipe
            d_iChildErrPipe.writtenBy(STDERR_FILENO);

        if (d_mode & (IGNORE_COUT | IGNORE_CERR))  // ignores cout/cerr
        {
            int fd = ::open("/dev/null", O_WRONLY);

            if (fd == -1)
                throw Exception() << "Process " << d_command << 
                                                    ": can't open /dev/null";

            Redirector redirector(fd);
  
            if (d_mode & IGNORE_COUT)                   //  ignores COUT
                redirector.swallow(Redirector::STDOUT);

            if (d_mode & IGNORE_CERR)                   //  ignores CERR
                redirector.swallow(Redirector::STDERR);
        }
    }    
}




