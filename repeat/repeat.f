template <typename Counter, typename First, typename ...Params>
void repeat(Counter counter, First &&first, Params &&...params)
{
    for (; counter; --counter)
        Repeat__<TypeTrait<First>::isClass>::call(
                                std::forward<First>(first), 
                                std::forward<Params>(params)...);
}    
