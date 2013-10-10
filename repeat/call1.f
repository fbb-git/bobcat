template <typename Fun, typename ...Params>
inline void Repeat__<false>::call(Fun fun, Params &&...params)
{
    fun(std::forward<Params>(params)...);
}
