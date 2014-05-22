template <typename Clock, typename Duration> 
std::cv_status SharedCondition::wait_until(                      
    std::chrono::time_point<Clock, Duration> const &absTime)
{
    d_status = INDETERMINATE;

    std::thread waitThread(waiter<Clock, Duration>, absTime, 
                                                        &d_cond, &d_status);
    waitThread.detach();

    wait();

    return d_status == INDETERMINATE ?      // should use a mutex for d_status
                std::cv_status::no_timeout 
           : 
                std::cv_status::timeout;
}
