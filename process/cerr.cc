#include "process.hh"

std::istream &Process::cerr()
{
    static bool called = false;

    if (not called)
    {
        called = true;
        std::cerr << "WARN: replace Process::cerr() calls by "
                                      "Process::childErrStream() calls\n";
    }

    return childErrStream();
}

