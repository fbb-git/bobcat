#include "sharedcondition.ih"

void SharedCondition::lock()
{
    Data data = prepare();

    data.condition->lock();
    d_shmem.seek(data.offset);
}
