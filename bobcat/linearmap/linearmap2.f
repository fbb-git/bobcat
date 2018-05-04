// LinearMap(initializer_list<value_type> initial)

template <typename Key, typename Value>
inline LinearMap<Key, Value>::
    LinearMap(std::initializer_list<value_type> initial)
{
    for (auto &value: initial)
        insert(value);
}
