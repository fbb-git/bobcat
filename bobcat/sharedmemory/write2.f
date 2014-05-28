template <typename Type>
int SharedMemory::write(Type const &value, std::ios::off_type offset,
                        std::ios::seekdir origin) 
{
    if (seek(offset, origin) == -1)
        throw Exception() << "SharedMemory::write: seek to " << offset <<
                                                                "failed";
    return write(value);
}
