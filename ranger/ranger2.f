template <typename Data>
Ranger<Data *> ranger(Data *begin, Data *end)
{
    return Ranger<Data *>(begin, end);
}
