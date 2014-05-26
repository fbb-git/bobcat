template <typename Type>
inline int SharedMemory::read(Type *value)
{
    return read(reinterpret_cast<char const *>(value), sizeof(Type));
}
