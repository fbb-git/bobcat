template <typename Type>
inline int OSharedStream::write(Type const *value)
{
    return write(reinterpret_cast<char const *>(value), sizeof(Type));
}
