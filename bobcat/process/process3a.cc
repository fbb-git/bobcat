#include "process.ih"

Process::Process(size_t mode, std::string const &command)
:
    Process(200, static_cast<IOMode>(mode & ALL_IOMODES), NO_PATH, 0, command)
{
    static bool called = false;
    if (not called)
    {
        called = true;
        std::cerr << "`Process(size_t, std::string const &)' is obsoleted, "
            "please recompile\n";
    }
}
