template <typename Clock, typename Duration, typename Predicate> 
bool SharedCondition::wait_until(                      
    std::chrono::time_point<Clock, Duration> const &absTime, Predicate pred)
{
    Data data = prepare();

    bool ret = true;

    while (not pred())
    {
        if (waiter(data.condition, absTime.time_since_epoch().count()) 
            == std::cv_status::timeout
        )
        {
            ret = pred();
            break;
        }
    }

    d_shmem.seek(data.offset);
    return ret;
}
