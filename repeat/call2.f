template <typename Class, typename Member, typename ...Params>
inline void Repeat__<true>::call(Class &obj, Member member, 
                                                    Params &&...params)
{
    (obj.*member)(std::forward<Params>(params)...);
}
