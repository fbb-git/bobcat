#include "csv.ih"

void CSV::assign(size_t idx, std::string &element)
{
    element = String::trim(element);

    bool avail;
    if (element.empty())
        avail = false;
    else if (d_type[idx] == 'S')
        avail = true;
    else 
    {
        try
        {
            stod(element);
            avail = true;
        }
        catch (...)
        {
            avail = false;
        }
    }
    d_available[idx] = avail;
    d_field[idx] = element;
}
