#include "process.ih"

Process::Process(size_t mode, ProcessType processType, size_t timeLimit, 
                 string const &command)
:
    Process(200, static_cast<IOMode>(mode & ALL_IOMODES), processType, 
            timeLimit, command)
{
    static bool called = false;
    if (not called)
    {
        called = true;
        std::cerr << 
            "`Process(size_t, size_t timeLimit, std::string const &)' "
            "is obsoleted, please recompile\n";
    }
}
