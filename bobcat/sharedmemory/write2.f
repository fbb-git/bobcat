template <typename Type>
int SharedMemory::write(Type const &value, std::ios::off_type offset,
                        std::ios::seekdir origin) 
{
    seek(offset, origin);
    return write(value);
}
