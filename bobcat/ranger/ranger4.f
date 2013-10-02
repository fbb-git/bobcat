template <typename Data>
Ranger<Data *> ranger(Data *begin, size_t count)
{
    return Ranger<Data *>(begin, begin + count);
}
