inline void SharedSegment::lock(size_t idx)
{
    d_block[idx].lock();
}
