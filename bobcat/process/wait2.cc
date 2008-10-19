#include "process.ih"

size_t Process::wait(size_t sec, size_t msec)
{
    std::cerr << "Process::wait() is obsolete: do not call\n";
//    d_selector.setAlarm(sec, msec);
//    return whichStream();
    return -1;
}
