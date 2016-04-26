template <typename Fun, typename ...Params>
bool Semaphore::wait(Fun fun, Params &&...args)
{
    std::unique_lock<std::mutex> lk(d_mutex);   // get the lock
    while (d_nAvailable == 0)
    {
        d_condition.wait(lk);   // see 'wait.cc' 
                                                    // called on notifications
        if (not fun(std::forward<Params>(args)...))
            return false;
    }
    --d_nAvailable;              // dec. semaphore
    return true;
}

