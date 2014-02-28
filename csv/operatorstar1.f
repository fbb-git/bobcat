template <typename Type>
inline typename IUO::CSV<Type>::type 
                    CSV::const_iterator<Type>::operator*() const
{
    return d_csv->get<Type>(d_idx);
}
