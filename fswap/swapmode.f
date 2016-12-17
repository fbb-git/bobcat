struct SwapMode
{
    enum Enum
    {
        STDSWAP,
        SWAPMEMBER
    };
};

template <SwapMode::Enum swapMode>
struct ModeType
{};


