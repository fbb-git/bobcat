template <typename Iterator, typename Type>
Iterator binary_search(Iterator begin, Iterator end, Type const &value)
{
    Iterator ret = end;

    while (begin != end)
    {
        Iterator mid = begin + (end - begin >> 1);
        if (value < *mid)       // left half
            end = mid;
        else if (*mid < value)  // right half
            begin = mid + 1;
        else
            return mid;
    }
    return ret;
}
