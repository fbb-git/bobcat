template <typename Type>
CSV::const_iterator<Type>::const_iterator(CSV const *csv, size_t idx)
:
    d_csv(csv),
    d_idx(idx)   
{}
