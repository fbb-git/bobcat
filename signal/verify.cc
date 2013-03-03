#include "signal.ih"

void Signal::verify(size_t signum, char const *member)
{
    if (signum > static_cast<size_t>(SIGRTMAX))
        throw Exception(1) <<  member << " signal " << signum << " exceeds "
                        "max. signum (" << SIGRTMAX << ')';
}
