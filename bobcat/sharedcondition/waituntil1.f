template <typename Clock, typename Duration> 
std::cv_status SharedCondition::wait_until(                      
    std::chrono::time_point<Clock, Duration> const &absTime)
{
    Data data = prepare();

    auto ret = waiter(data.condition, absTime.time_since_epoch().count());
    d_shmem.seek(data.offset);
    return ret;
}
