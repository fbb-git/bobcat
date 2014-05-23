inline void SharedCondition::notifyAll() noexcept
{
    pthread_cond_broadcast(&d_cond);
}
