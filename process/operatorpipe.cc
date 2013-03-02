#include "process.ih"

/*
    Process constructors or public IOMode setters cannot set the PIPE
    flag. The PIPE flag is set for the RHS process by operator| to indicate
    that the parent process must ignore its CIN flag.

    operator|, when called for three processes will have the PIPE flag set as
    follows: 

            p1  |   p2  |   p3
                   PIPE    PIPE

    The PIPE flag ignores the CIN flag in the parent process, but the child
    process will still read from d_pipeToChildCin, which (at the parent
    process) was initialized from the LHS's d_pipeFmChildCout Pipe: output
    written by the LHS process is read by the RHS's child process.

    The PIPE flag also leaves the RHS's ostream untouched. If the LHS process
    used the CIN flag then the RHS's ostream is provided with the LHS's
    OFdStreambuf's address, so information inserted into the RHS object will
    be received by the LHS's child process.

LHS:
    No DIRECT actions, so DIRECT is removed.

    The output must be obtained from the child process:
        If MERGE_COUT_CERR was set: all done for the output part since the
        output becomes available through the pipe.

        If COUT was not set: set COUT, so output becomes available through the
        pipe.

    execute start();

    If CIN or PIPE was set obtain the address of OFdStreambuf, resetting
        the ostream buffer to 0: information is not inserted into the LHS.

    Obtain the Pipe associated with d_pipeFromChildCout: this pipe will be
        assigned to the RHS's d_toChildCinBuf so the RHS will read the LHS's
        output 

--------------------------------------------------------------------------

Assign the LHS's OFdStreambuf's address to the RHS's ostream, forwarding
information inserted into the RHS Process to the first child process of the
pipe-sequence 

Assign the Pipe associated with LHS's d_pipeFromChildCout to the RHS's
d_pipeToChildCin, connecting the LHS's output to the RHS's input


---------------------------------------------------------------------------
RHS:
    Remove DIRECT
    Set PIPE and CIN

*/

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

    lhs.d_setMode |= Process::OUT_PIPE; // This is the output end of the pipe

    lhs.start();                        // forking() does the real work

    rhs.d_oChildInPipe = lhs.d_iChildOutPipe;

    if (lhs.d_oChildIn.rdbuf() != 0)      
    {
        lhs.d_oChildIn.rdbuf(0);
        rhs.d_oChildInbuf.open(lhs.d_oChildInbuf.fd(), 200);
        rhs.d_oChildIn.rdbuf(&rhs.d_oChildInbuf);
    }

                                        // this is the input end of the pipe
    rhs.d_setMode |= Process::IN_PIPE | Process::CIN;
    rhs.d_mode |= Process::CIN;

    return rhs;                         // to start do, e.g., (a|b).start()
}


}


