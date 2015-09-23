#include "sharedcondition.hh"

void SharedCondition::notifyAll() noexcept
{
    Data data = prepare();
    pthread_cond_broadcast(&data.condition->d_cond);
    d_shmem->seek(data.offset);
}
