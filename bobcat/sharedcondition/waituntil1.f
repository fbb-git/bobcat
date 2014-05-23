template <typename Clock, typename Duration> 
inline std::cv_status SharedCondition::wait_until(                      
    std::chrono::time_point<Clock, Duration> const &absTime)
{
    return waiter(absTime.time_since_epoch().count());
}
