inline TableBase::Element::Element(std::string text, 
                                   std::ios_base &(*manip)(std::ios_base &))
:
    d_text(text),
    d_manip(manip)
{}
