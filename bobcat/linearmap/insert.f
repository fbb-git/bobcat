//     pair<iterator, bool> insert(value_type const keyvalue);

template <typename Key, typename Value, typename Alloc>
std::pair<LinearMap<Key, Value, Alloc>::iterator, bool> 
    LinearMap<Key, Value, Alloc>::insert(value_type const &keyvalue)
{
    bool inserted;

    auto iter = find(keyvalue.first);
    if (iter != end())
        inserted = false;
    else
    {
        iter = end();
        push_back(keyvalue);
        inserted = true;
    }
    
    return std::pair<LinearMap<Key, Value, Alloc>::iterator, bool> 
                    (iter, inserted);
}
