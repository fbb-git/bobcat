template <typename Type>
inline typename IUO::Category<Type>::type CSV::get(size_t idx) const
{
    try
    {
        return IUO::Avail<
                        typename IUO::Category<Type>::type, 
                        IUO::Category<Type>::nr
                >::available(d_field[idx]);
    }
    catch (...)
    {
        return Type();
    }
}
