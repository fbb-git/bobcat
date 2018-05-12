inline A2x::A2x(A2x &&tmp)
:
    std::istringstream(std::move(tmp))
{}
