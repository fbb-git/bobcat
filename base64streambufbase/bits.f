template <int from, int size, int shl>
inline int Base64StreambufBase::bits(int value)
{
    return value == EOF ? 0 :
            (value & ((1 << (from + size)) - 1)) >> from << shl;
}
