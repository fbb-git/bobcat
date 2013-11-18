inline void SharedMemory::swap(SharedMemory &other)
{
    FBB::fswap(*this, other);
}
