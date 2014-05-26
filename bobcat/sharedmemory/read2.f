template <typename Type>
int SharedMemory::read(std::ios::off_type offset, Type *value, 
                        std::ios::seekdir origin) 
{
    if (seek(offset, origin) == -1)
        throw Exception() << "SharedMemory::read: failed to seek " << offset;
                            
    return read(value);
}
