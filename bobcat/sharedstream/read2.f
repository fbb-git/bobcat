template <typename Type>
int SharedStream::read(std::ios::off_type offset, Type *value, 
                        std::ios::seekdir origin) 
{
    return seekg(offset, origin) ?
                read(value)
            :
                -1;
}
