#include "signal.hh"

void Signal::ignore(size_t signum)
{
    verify(signum, "Signal::ignore");

    signal(signum, SIG_IGN);

    d_signals[signum].clear();
}
