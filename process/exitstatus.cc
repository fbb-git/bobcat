#include "process.ih"

int Process::exitStatus() const
{
    return d_data->d_exitStatus;
}
