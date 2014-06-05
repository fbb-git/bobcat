template <typename Type>
int SharedMemory::write(std::ios::off_type offset, Type const *value, 
                        std::ios::seekdir origin) 
{
    if (seek(offset, origin) == -1)
        throw Exception() << "SharedMemory::write: seek to " << offset <<
                                                                "failed";
    return write(value);
}
