inline bool ISharedStream::truncate(std::streamsize offset)
{
    return sharedMemory().truncate(offset);
}
