template <typename Type>
Process &Process::operator<<(Type const &value)
{
    if (active())
        dynamic_cast<std::ostream &>(*this) << value;

    return *this;
}
