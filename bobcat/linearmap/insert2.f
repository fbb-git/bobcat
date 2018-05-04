//  iterator insert(iterator pos, value_type const &keyValue);

template <typename Key, typename Value>
typename LinearMap<Key, Value>::iterator
    LinearMap<Key, Value>::insert(iterator pos, 
              value_type const &keyvalue)
{
    auto iter = find(keyvalue.first);
    if (iter == end())
    {
        push_back(keyvalue);
        iter = iterator(&Base::back());
    }
    return iter;
}
