template <typename Type>
inline typename IUO::CSV<Type>::type CSV::get(size_t idx) const
{
    try
    {
        return IUO::Avail<
                        typename IUO::CSV<Type>::type, 
                        IUO::CSV<Type>::cat
                >::get(d_field[idx]);
    }
    catch (...)
    {
        return Type();
    }
}
