#include "sharedcondition.ih"

cv_status  SharedCondition::waiter(int64_t count)
{
    struct timespec timeSpec{
        static_cast<time_t>(count / 1000000000LL),
        static_cast<long>(count % 1000000000LL)};

    int ret = pthread_cond_timedwait(&d_cond, mutexPtr(), &timeSpec);

    return ret == 0 ? cv_status::no_timeout : cv_status::timeout;
}
