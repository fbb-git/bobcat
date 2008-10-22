#include "process.ih"

namespace 
{
    bool notice(bool warned, char const *prototype)
    {
        if (!warned)
            std::cerr << 
                "[WARNING] `" << prototype << "'\n"
                "is OBSOLETE and will shortly be REMOVED from Bobcat\n";

        return true;
    }
}    

void Process::setPath(ProcessType type)
{
    static bool warned = false;

    warned = notice(warned, "Process::setPath(ProcessType type)");
    d_processType = type;
}

Process::Process(size_t waitSeconds, std::string const &command, iomode mode)
:
    d_childCin(0),
    d_childCout(0),
//    d_childCerr(0),   

    d_mode(mode),
    d_processType(NO_PATH),
    d_waitSeconds(waitSeconds),
    d_active(false)
{
    static bool warned = false;

    warned = notice(warned, "Process::Process(waitSeconds, command, mode)");
    setCommand(command);
    open(d_childCout, d_childCin);
}

Process::Process(std::string const &command, iomode mode)
:
    d_childCin(0),
    d_childCout(0),
//    d_childCerr(0),   

    d_mode(mode),
    d_processType(NO_PATH),
    d_waitSeconds(0),
    d_active(false)
{
    static bool warned = false;

    warned = notice(warned, "Process::Process(command, mode)");
    setCommand(command);
    open(d_childCout, d_childCin);
}


size_t Process::wait()
{
    static bool warned = false;

    warned = notice(warned, "Process::wait() [**now defunct **]");
    return -1;
}

size_t Process::wait(size_t sec, size_t msec)
{
    static bool warned = false;

    warned = notice(warned, "Process::wait(sec, msec)  [**now defunct **]");
    return -1;
}
