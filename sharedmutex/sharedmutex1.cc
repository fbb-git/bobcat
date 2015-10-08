#include "sharedmutex.ih"

SharedMutex::SharedMutex()
{
    pthread_mutexattr_t mutex_attr;
    
    pthread_mutexattr_init(&mutex_attr);
        // pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutexattr_setpshared(&mutex_attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&d_mutex, &mutex_attr);
}
