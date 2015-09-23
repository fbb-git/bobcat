#include "sharedcondition.hh"

SharedCondition::Condition::Condition()
{
    pthread_condattr_t cond_attr;
    pthread_condattr_init(&cond_attr);
    pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED);

    pthread_cond_init(&d_cond, &cond_attr);
}
