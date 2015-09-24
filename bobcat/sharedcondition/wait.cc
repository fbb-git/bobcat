#include "sharedcondition.ih"

void SharedCondition::wait()
{
    Data data = prepare();
    pthread_cond_wait(&(data.condition->d_cond), data.condition->mutexPtr());
    d_shmem->seek(data.offset);
}
