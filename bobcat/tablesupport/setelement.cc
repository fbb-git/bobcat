//#include "tablesupport.ih"
//
//#include <iostream>
//
//void TableSupport::const_iterator::setElement()
//{
//    d_element.type = SKIP;
//
//    if (d_begin != d_end)
//    {
//        if (d_begin->begin == d_col)
//            d_element.type =  !d_sep ? USE : d_begin->type;
//        else if (d_col + 1 == d_begin->end) 
//            d_element.type =  !d_sep ? USE : d_begin->type;
//        else if (d_begin->begin < d_col && d_col < d_begin->end)
//            d_element.type = USE;
//    }
//    d_element.width = d_sep ? 
//                            d_support.sepWidth(d_col) 
//                        : 
//                            d_support.colWidth(d_col);
//}
//
//
