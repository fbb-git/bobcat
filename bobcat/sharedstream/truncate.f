bool SharedStream::truncate(std::streamsize offset)
{
    return sharedMemory().truncate(offset);
}
