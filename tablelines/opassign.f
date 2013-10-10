inline TableLines &TableLines::operator=(TableLines &&tmp)
{
    *this = std::move(tmp);
    return *this;
}
