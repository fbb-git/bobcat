inline void SharedSegment::unlock(size_t idx)
{
    d_block[idx].unlock();
}
