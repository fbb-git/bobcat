template <typename Clock, typename Duration, typename Predicate> 
bool SharedCondition::wait_until(                      
    std::chrono::time_point<Clock, Duration> const &absTime, Predicate pred)
{
    while (not pred())
    {
        if (wait_for(absTime) == cv_status::timeout)
            return pred();
    }
    return true;
}
