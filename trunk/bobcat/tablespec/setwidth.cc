#include "tablespec.ih"

void TableSpec::setWidth(WidthType type)
{
    d_widthFun = 
        ((d_widthType = type) == EqualWidth) ?
            &TableSpec::maxWidth
        :
            &TableSpec::columnWidth;

    d_tableSupport.setParam(d_widthType == EqualWidth ? d_maxWidth : 0);
}
