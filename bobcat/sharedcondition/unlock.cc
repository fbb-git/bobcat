#include "sharedcondition.hh"

void SharedCondition::unlock()
{
    Data data = prepare();

    data.condition->unlock();
    d_shmem->seek(data.offset);
}
