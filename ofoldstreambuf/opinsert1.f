inline std::ostream &operator<<(std::ostream &out, lm const &idt)
{
    return idt.modify(out);
}
