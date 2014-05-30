bool OSharedStream::truncate(std::streamsize offset)
{
    return sharedMemory().truncate(offset);
}
