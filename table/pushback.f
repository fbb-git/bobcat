inline void Table::push_back(Element const &element)
{
    d_tabulated = false;
    d_string.push_back(element);
}
