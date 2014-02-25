template <typename Type>
inline typename IUO::Category<Type>::type CSV::available(size_t idx) const
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
       throw Exception() << "Field " << idx << " not available";
    }
}



