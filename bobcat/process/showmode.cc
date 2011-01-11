#include "process.ih"

void Process::showMode(char const *lab)
{
    std::cerr << lab << ' ' << getpid() << ' ' << d_child.pid << " IOMode: ";

    if (d_mode & STD)
        std::cerr << "STD ";
    if (d_mode & CIN)
        std::cerr << "CIN ";
    if (d_mode & COUT)
        std::cerr << "COUT ";
    if (d_mode & CERR)
        std::cerr << "CERR ";
    if (d_mode & IGNORE_COUT)
        std::cerr << "IGNORE_COUT ";
    if (d_mode & IGNORE_CERR)
        std::cerr << "IGNORE_CERR ";
    if (d_mode & MERGE_COUT_CERR)
        std::cerr << "MERGE_COUT_CERR ";
    if (d_mode & DIRECT)
        std::cerr << "DIRECT ";

    if (d_setMode & IN_PIPE)
        std::cerr << "IN_PIPE ";
    if (d_setMode & OUT_PIPE)
        std::cerr << "OUT_PIPE ";
    if (d_setMode & CLOSE_ON_EXEC)
        std::cerr << "CLOSE_ON_EXEC ";

    std::cerr << '\n';
}

