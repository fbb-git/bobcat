#include "sharedcondition.hh"

cv_status  SharedCondition::waiter(Condition *cond, int64_t count)
{
    struct timespec timeSpec{
        static_cast<time_t>(count / 1000000000LL),
        static_cast<long>(count % 1000000000LL)
    };

    int ret = pthread_cond_timedwait(&cond->d_cond, cond->mutexPtr(), 
                                     &timeSpec);

    return ret == 0 ? cv_status::no_timeout : cv_status::timeout;
}
