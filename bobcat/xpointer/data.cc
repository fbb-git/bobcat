#include "xpointer.ih"

std::unique_ptr<Display, Xpointer::DeleterType> 
                                        Xpointer::s_theDisplay(0, deleter);
