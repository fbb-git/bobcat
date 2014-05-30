template <typename Type>
int OSharedStream::write(std::ios::off_type offset, Type const *value, 
                        std::ios::seekdir origin) 
{
    return seekp(offset, origin) ?
                write(value)
            :
                -1;
}
