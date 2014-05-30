template <typename Type>
inline int ISharedStream::read(Type *value)
{
    return read(reinterpret_cast<char *>(value), sizeof(Type));
}
