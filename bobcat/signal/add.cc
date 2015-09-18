#include "signal.hh"

void Signal::add(size_t signum, SignalHandler &object)
{
    verify(signum, "Signal::add");

    if (d_signals.size() <= signum)
        d_signals.resize(signum + 1);

    d_signals[signum].push_back(&object);

    signal(signum, handler); 
}
