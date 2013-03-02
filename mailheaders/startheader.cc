#include "mailheaders.ih"

MailHeaders::HdrLine *MailHeaders::startHeader(string const &line)
{
                                                    // find the end of the   
    unsigned pos = line.find_first_of(" \t");       // header label

    if (pos == string::npos)                        // no found: only a label
        pos = line.length();

    string label = line.substr(0, pos);             // grab the label

    unsigned index = lookup(label.c_str(), FULL);   // find its index

    if (index == string::npos)                      // label not found
    {
        index = d_index.size();                     // determine the index
                                                    // to which a new element
                                                    // is added,

        d_index.push_back                           // add a new element
        (                                           // to d_index
            HdrPair(label, Hdr(1, HdrLine(1, size())))
        );
    }
    else                                            // or add new HdrEntry
                                                    // to an existing Hdr
        d_index[index].second.push_back(HdrLine(1, size()));

    return &d_index[index].second.back();           // return address of
                                                    // last used HdrEntry
}





