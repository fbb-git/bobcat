template <typename Iter>
void Table::fill(Iter it, Iter end)
{
    TableBase::clear();

    while (it != end)
    {
        std::ostringstream str;
        str << *it++;
        push_back(str.str());
    }
}
