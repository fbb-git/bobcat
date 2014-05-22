inline void SharedCondition::notify_all() noexcept
{
    pthread_cond_broadcast(&d_cond);
}
