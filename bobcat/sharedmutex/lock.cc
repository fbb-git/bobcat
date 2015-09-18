#include "sharedmutex.hh"

void SharedMutex::lock()
{
    if (pthread_mutex_lock(&d_mutex) != 0)
        throw Exception() << "SharedMutex::lock: failed to lock the segment";
}
