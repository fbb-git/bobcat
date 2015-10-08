#include "signal.ih"

void Signal::reset(size_t signum)
{
    verify(signum, "Signal::reset");

    signal(signum, SIG_DFL);

    d_signals[signum].clear();
}
