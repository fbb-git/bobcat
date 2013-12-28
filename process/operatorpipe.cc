#include "process.ih"

// See ../README.process-pipe for an explanation of the inner workings of
// operator| 

namespace FBB
{

Process &operator|(Process &lhs, Process &rhs)
{
                                        // make sure output is available
    if (not (lhs.d_mode & Process::MERGE_COUT_CERR))
    {
        lhs.d_mode |= Process::COUT;
        lhs.d_setMode |= Process::COUT;
    }

        // all but the first process has IN_PIPE set
    if 
    (
        (lhs.d_setMode & Process::CIN)
        && 
        not (lhs.d_setMode & Process::IN_PIPE)
    )
        lhs.d_setMode |= Process::CLOSE_ON_EXEC;

                                        // This is the output end of the pipe
    lhs.d_setMode |= Process::PIPES_OK | Process::OUT_PIPE; 
    rhs.d_setMode |= Process::PIPES_OK;

    lhs.start();                        // forking() does the real work

#ifdef BOBCAT_DIY_CLOEXEC_
    rhs.d_closedByChild = lhs.d_closedByChild;  // children close the initial 
                                                // writing ends of the pipes
                                                // to the 1st process
#endif

    rhs.d_oChildInPipe = lhs.d_iChildOutPipe; 
                            // copy the input fm the lhs's child to the rhs's
                            // output. lhs.iChildOutPipe only has an open
                            // read-pipe and will be available to the rhs's
                            // child process to read via its stdin, thus
                            // connecting lhs's output to the rhs's input

    if (lhs.d_oChildIn.rdbuf() != 0)      
    {
        lhs.d_oChildIn.rdbuf(0);
        rhs.d_oChildInbuf.open(lhs.d_oChildInbuf.fd(), 200);
        rhs.d_oChildIn.rdbuf(&rhs.d_oChildInbuf);
    }

                                        // this is the input end of the pipe
    rhs.d_setMode |= Process::CIN | Process::IN_PIPE;
    rhs.d_mode |= Process::CIN;

    return rhs;                         // to start do, e.g., (p1|p2).start()
}


}


