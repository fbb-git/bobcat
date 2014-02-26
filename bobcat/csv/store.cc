#include "csv.ih"

void CSV::store(size_t idx, string const &value)
{
    string trimmed = String::trim(value);

    bool ok = true;
    try
    {
        switch (d_type[idx])
        {
            case '-':           // ignore 'X' and '-' fields
            case 'X':
            return;

            case 'I':
                stoll(trimmed);
            break;
                
            case 'D':
                stold(trimmed);
            break;

            case 'S':
                ok = not trimmed.empty();
            break;
        }
    }
    catch (...)
    {
        ok = false;
    }

    d_field.push_back(trimmed);
    d_available.push_back(ok);
}
