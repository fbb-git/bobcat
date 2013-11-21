inline void SharedSegment::nReadableLock()
{
    d_nReadableMutex.lock();
}
