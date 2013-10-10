inline TableSupport::const_iterator TableSupport::end(size_t row) const
{
    const_iterator ret(*this, row, false);
    return ret;
}
