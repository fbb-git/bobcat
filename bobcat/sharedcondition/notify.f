inline void SharedCondition::notify() noexcept
{
    pthread_cond_signal(&d_cond);
}
