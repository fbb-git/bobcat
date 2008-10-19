#include "process.ih"

void Process::childRedirections()
{
    if (d_mode & CIN)
        d_child_inp->readFrom(STDIN_FILENO);  // set up the redirected pipes
    
    if (d_mode & MERGE_COUT_CERR)
    {
        int fd[] = {STDOUT_FILENO, STDERR_FILENO};
        d_child_outp->writtenBy(fd, 2);
    }
    else
    {
        if (d_mode & COUT)
            d_child_outp->writtenBy(STDOUT_FILENO);
        
        if (d_mode & CERR)
            d_child_errp->writtenBy(STDERR_FILENO);

        if 
        (
            (d_mode & IGNORE_COUT && !(d_mode & COUT))
            ||
            (d_mode & IGNORE_CERR && !(d_mode & CERR))
        )
        {
            int fd = ::open("/dev/null", 0);

            if (fd == -1)
                throw Errno("Process ") << insertable << d_command << 
                        ": can't open /dev/null" << throwable;

            Redirector redirector(fd);
        
            if (d_mode & IGNORE_COUT)
                redirector.swallow(Redirector::STDOUT);

            if (d_mode & IGNORE_CERR)
                redirector.swallow(Redirector::STDERR);
        }
    }    
}




