#include "tablesupport.ih"

void TableSupport::setParam(std::ostream &ostr, size_t rows, 
                            std::vector<size_t> const &colWidth,
                            size_t maxWidth)
{
    d_streamPtr = &ostr;
    d_rows = rows;
    d_colWidth = &colWidth;
    d_maxWidth = maxWidth;  // 0 if colWidth should be used.
    d_tableWidth = d_maxWidth ? 
                        d_maxWidth * colWidth.size()
                    :
                        std::accumulate(colWidth.begin(), 
                                        colWidth.end(), 0);
}
