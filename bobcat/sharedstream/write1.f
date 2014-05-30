template <typename Type>
inline int SharedStream::write(Type const *value)
{
    return write(reinterpret_cast<char const *>(value), sizeof(Type)) ?
                static_cast<int>(tellp())
            :
                -1;
}
