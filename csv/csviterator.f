template <typename Type>
bool operator==(CSV::const_iterator<Type> const &lhs, 
                CSV::const_iterator<Type> const &rhs);

template <typename Type>
class CSV::const_iterator
:  
    private IUO::CSViteratorData<Type>,
    public  std::iterator<std::bidirectional_iterator_tag, std::string>
{
    friend CSV;
    friend bool operator==<Type>(const_iterator<Type> const &lhs,
                                 const_iterator<Type> const &rhs);

    CSV const *d_csv;
    size_t d_idx;

    public:
        typedef Type const &reference;

        const_iterator() = default;
    
        const_iterator<Type> &operator++();
        const_iterator<Type> operator++(int);
    
        typename IUO::CSV<Type>::type operator*() const;
        Type const *operator->() const;
    
    private:
        const_iterator(CSV const *csv, size_t idx);

        friend class std::reverse_iterator<const_iterator<Type>>;
        const_iterator<Type> &operator--();
};


template <typename Type>
struct CSV::const_reverse_iterator: public 
    std::reverse_iterator<CSV::const_iterator<Type>>
{
    const_reverse_iterator() = default;

    const_reverse_iterator(const_iterator<Type> const &iter)
    :
        std::reverse_iterator<const_iterator<Type>>(iter)
    {}
};






