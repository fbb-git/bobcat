#include "tablelines.ih"

void TableLines::outLine(Field const &field,  ostream &out) 
{
    if (field.width == 0)
        return;

    if (field.type == SKIP)
        out << setw(field.width) << " ";
    else if ((field.type & (LEFT_FULL | USE | RIGHT_FULL)))
        out << setfill('-') << setw(field.width) << "-" << setfill(' ');
    else if (field.type & LEFT_MID)
    {
        out << setw(field.width / 2) << " " <<
            setfill('-') << 
            setw(field.width - field.width / 2) << "-" << setfill(' ');
    }
    else
    {
        out << setfill('-') << 
            setw(field.width - field.width / 2) << "-" << setfill(' ') <<
            setw(field.width / 2) << " ";
    }
}


