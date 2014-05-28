template <typename Type>
int SharedMemory::read(Type *value, std::ios::off_type offset, 
                        std::ios::seekdir origin) 
{
    if (seek(offset, origin) == -1)
        throw Exception() << "SharedMemory::read: seek to " << offset <<
                                                                "failed";
                            
    return read(value);
}
