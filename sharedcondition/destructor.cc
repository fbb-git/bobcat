#include "sharedcondition.hh"

SharedCondition::~SharedCondition()
{
    if (d_shmem)
        unlock();
}

