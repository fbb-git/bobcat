inline void SharedCondition::wait()
{
    pthread_cond_wait(&d_cond, mutexPtr());
}
