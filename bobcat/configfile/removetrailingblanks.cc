#include "configfile.ih"

                                                // `line' must have content.
void ConfigFile__::removeTrailingBlanks(string &line)
{
                            // convert idx of last non-blank char to 
                            // a length, resize to that length.
    line.resize(1 + line.find_last_not_of(" \t"));
}   
