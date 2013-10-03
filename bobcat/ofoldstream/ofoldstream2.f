inline OFoldStream::OFoldStream(std::ostream &out, 
                    size_t leftIndent, size_t rightMargin, 
                    TabsOrBlanks tob, TrailingBlanks tb)
:
    OFoldStreambuf(out, leftIndent, rightMargin, tob, tb),
    std::ostream(this)
{}
