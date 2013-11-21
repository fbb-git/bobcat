inline void SharedStreambuf::setMemory(SharedMemory &&tmp)
{
    d_memory = std::move(tmp);
}
