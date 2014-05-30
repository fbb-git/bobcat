template <typename Type>
inline int SharedStream::read(Type *value)
{
    return read(reinterpret_cast<char *>(value), sizeof(Type)) ?
                gcount()
            :
                -1;
}
