#include "tablelines.ih"

#include <iostream>

void TableLines::outLine(Element const &element, int *type,
                        ostream &out)
{
    if (element.width == 0)
        return;

    if (*type == 0 && element.type != 0)
        *type = element.type;

    if (element.type == SKIP)
    {
        if (*type & RIGHT_MID && element.type == SKIP)
        {
            out << setfill('-') << 
            setw(element.width - element.width / 2) << "-" << setfill(' ') <<
            setw(element.width / 2) << " ";
            *type = RIGHT_FULL;
        }
        else
            out << setw(element.width) << " ";
    }
    else if ((element.type & (LEFT_FULL | USE | RIGHT_FULL)))
        out << setfill('-') << setw(element.width) << "-" << setfill(' ');
    else if (element.type & LEFT_MID)
    {
        out << setw(element.width / 2) << " " <<
            setfill('-') << 
            setw(element.width - element.width / 2) << "-" << setfill(' ');
    }
}


