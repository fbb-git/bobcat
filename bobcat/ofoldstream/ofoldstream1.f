inline OFoldStream::OFoldStream(char const *fname, 
                    size_t leftIndent, size_t rightMargin, 
                    TabsOrBlanks tob, TrailingBlanks tb)
:
    OFoldStreambuf(fname, leftIndent, rightMargin, tob, tb),
    std::ostream(this)
{}
