inline pthread_mutex_t *SharedMutex::mutexPtr()
{
    return &d_mutex;
}
