#include "signal.hh"

Signal *Signal::s_signal;

Signal &Signal::instance()
{
    if (s_signal == 0)
        s_signal = new Signal;

    return *s_signal;
}
