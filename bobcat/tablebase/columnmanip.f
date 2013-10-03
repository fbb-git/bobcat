inline Manipulator TableBase::columnManip(size_t col) const
{
    Manipulator manip = d_align[col].manip();
    return manip ? manip : std::right;
}
