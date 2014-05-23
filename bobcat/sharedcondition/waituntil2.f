template <typename Clock, typename Duration, typename Predicate> 
bool SharedCondition::wait_until(                      
    std::chrono::time_point<Clock, Duration> const &absTime, Predicate pred)
{
    while (not pred())
    {
        if (wait_until<Clock, Duration>(absTime) == std::cv_status::timeout)
            return pred();
    }
    return true;
}
