template <typename Predicate>
void SharedCondition::wait(Predicate pred)
{
    Data data = prepare();
    while (not pred())
        pthread_cond_wait(&(data.condition->d_cond), 
                          data.condition->mutexPtr());
    d_shmem->seek(data.offset);
}
