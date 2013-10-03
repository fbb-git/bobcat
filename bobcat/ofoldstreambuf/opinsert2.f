inline std::ostream &operator<<(std::ostream &out, mlm const &idt)
{
    return idt.modify(out);
}
