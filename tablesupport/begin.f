inline TableSupport::const_iterator TableSupport::begin(size_t row) const
{
    const_iterator ret(*this, row, true);
    return ret;
}
