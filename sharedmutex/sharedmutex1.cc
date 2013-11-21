#include "sharedmutex.ih"

SharedMutex::SharedMutex()
{
    pthread_mutexattr_t mutex_attr;
    
    pthread_mutexattr_init(&mutex_attr);
        // pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutexattr_setpshared(&mutex_attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&d_mutex, &mutex_attr);
    


//    pthread_condattr_t cond_attr;
//    
//    pthread_condattr_init(&cond_attr);
//    pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED);
//    pthread_cond_init(&d_condvar, &cond_attr);
}
