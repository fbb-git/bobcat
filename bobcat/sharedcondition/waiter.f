template <typename Clock, typename Duration>
void SharedCondition::waiter(
        std::chrono::time_point<Clock, Duration> const &absTime,
        pthread_cond_t *cond, Status *status)

{
    std::this_thread::sleep_until(absTime);
    if (*status == INDETERMINATE)           // should use a mutex for d_status
        *status = TIMEOUT;
    pthread_cond_signal(cond);
}
