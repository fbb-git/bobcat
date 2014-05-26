template <typename Type>
int SharedMemory::read(Type *value, std::ios::off_type offset,
                        std::ios::seekdir origin) 
{
    seek(offset, origin);
    return read(value);
}
