#include "sharedcondition.hh"

void SharedCondition::notify() noexcept
{
    Data data = prepare();
    pthread_cond_signal(&(data.condition->d_cond));
    d_shmem->seek(data.offset);
}
