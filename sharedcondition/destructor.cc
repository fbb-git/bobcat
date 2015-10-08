#include "sharedcondition.ih"

SharedCondition::~SharedCondition()
{
    if (d_shmem)
        unlock();
}

