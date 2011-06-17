#include "ofoldstreambuf.ih"

void OFoldStreambuf::setMargins(size_t leftMargin, size_t rightMargin)
{
    d_rightMargin = rightMargin;
    d_indent = leftMargin;
}
