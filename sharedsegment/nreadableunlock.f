inline void SharedSegment::nReadableUnlock()
{
    d_nReadableMutex.unlock();
}
