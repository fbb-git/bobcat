#include "process.ih"

size_t Process::wait()
{
    std::cerr << "Process::wait() is obsolete: do not call\n";
//    d_selector.noAlarm();
//    return whichStream();
    return -1;
}
