inline TableSupport::Field const
                            &TableSupport::const_iterator::operator*() const
{
    return *operator->();
}
