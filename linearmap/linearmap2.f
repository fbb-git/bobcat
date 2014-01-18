// LinearMap(initializer_list<value_type> initial)

template <typename Key, typename Value, typename Alloc>
inline LinearMap<Key, Value, Alloc>::
    LinearMap(std::initializer_list<value_type> initial)
{
    for (auto &value: initial)
        insert(value);
}
