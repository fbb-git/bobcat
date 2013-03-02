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

Process::Process(size_t timeLimit, std::string const &command, iomode mode)
:
    d_command(command),

    d_childCin(0),
    d_childCout(0),
    d_childCerr(0)
{
    static bool warned = false;

    warned = notice(warned, "Process::Process(timeLimit, command, mode)");
    initialize(timeLimit, mode, NO_PATH);
}

Process::Process(std::string const &command, iomode mode)
:
    d_command(command),

    d_childCin(0),
    d_childCout(0),
    d_childCerr(0)
{
    static bool warned = false;

    warned = notice(warned, "Process::Process(command, mode)");
    initialize(0, mode, NO_PATH);
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
