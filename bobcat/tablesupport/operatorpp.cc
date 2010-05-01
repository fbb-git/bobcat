//#include "tablesupport.ih"
//
//TableSupport::const_iterator &TableSupport::const_iterator::operator++()
//{
//    if (!d_sep)                     // each increment toggles the separator
//        ++d_col;                    // situation. Move to the next column
//                                    // after completing the separator column
//    d_sep = not d_sep;
//                                    // to the next column until we're 
//                                    // at the end or d_col has been reached
//    if (d_begin != d_end && d_col >= d_begin->end)
//        ++d_begin;
//
//    setElement();                   // determine how to handle this column
//
//    return *this;
//}
//
