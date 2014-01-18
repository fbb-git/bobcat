// value_type *findPtr(Key const &key) const

template <typename Key, typename Value, typename Alloc>
inline typename LinearMap<Key, Value, Alloc>::value_type * 
        LinearMap<Key, Value, Alloc>:: findPtr(Key const &key) const
{
    value_type *ptr = const_cast<value_type *>(&*begin());

    return std::find_if(ptr, ptr + size(), 
        [&](value_type const &value)
        {
            return key == value.first; 
        }
    );
}
