#include "signal.hh"

void Signal::remove(size_t signum, SignalHandler &object)
{
    verify(signum, "Signal::remove");

    if (d_signals.size() <= signum)
        throw Exception(1) << "no signal handlers for signal " << signum <<
                              " were installed";

    auto iter = 
        find(d_signals[signum].begin(), d_signals[signum].end(), &object); 

    if (iter == d_signals[signum].end())
        throw Exception(1) << "object " << &object << 
                " did not register a handler for signal " << signum;

    d_signals[signum].erase(iter);

    signal(signum, handler); 
}
