template <typename Type>
Process &Process::operator>>(Type &value)
{
    if ((available() & CHILD_COUT) || active())
        dynamic_cast<std::istream &>(*this) >> value;

    return *this;
}
