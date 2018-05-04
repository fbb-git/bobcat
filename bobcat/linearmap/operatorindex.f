//Value &operator[])Key const &key)

template <typename Key, typename Value>
        Value &LinearMap<Key, Value>::operator[](Key const &key)
{
    auto iter = find(key);
    if (iter != end())
        return iter->second;

    Base::push_back(value_type(key, Value()));
    return Base::back().second;
}

