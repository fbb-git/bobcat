inline GS__::Type operator|(GS__::Type lhs, GS__::Type rhs)
{
    return static_cast<GS__::Type>(
                        static_cast<int>(lhs) | static_cast<int>(rhs)
            );
}
