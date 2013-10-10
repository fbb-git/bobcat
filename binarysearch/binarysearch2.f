template <typename Iterator, typename Type, typename Comparator>
Iterator binary_search(Iterator begin, Iterator end, Type const &value, 
                       Comparator comparator)
{
    Iterator ret = end;

    while (begin != end)
    {
        Iterator mid = begin + (end - begin >> 1);
        if (comparator(value, *mid))        // left half
            end = mid;
        else if (comparator(*mid, value))   // right half
            begin = mid + 1;
        else
            return mid;
    }
    return ret;
}
