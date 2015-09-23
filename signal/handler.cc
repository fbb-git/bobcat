#include "signal.hh"

void Signal::handler(int signum)
{
    for (auto &obj: s_signal->d_signals[signum])
        obj->signalHandler(signum);
}
