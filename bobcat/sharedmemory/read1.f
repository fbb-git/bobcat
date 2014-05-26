template <typename Type>
inline int SharedMemory::read(Type *value)
{
    return read(reinterpret_cast<char *>(value), sizeof(Type));
}
