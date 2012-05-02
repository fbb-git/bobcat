#include "configfile.ih"

bool ConfigFile__::nextLine(istream &inStream, string &dest)
{
    dest.erase();
    string line;

    while (getline(inStream, line))
    {
        ++d_rawIndex;                               // at the next line

        trimLeft(line);

        bool appendNext = rmCommentAndEscapes(line);

        trimRight(line, appendNext);

        dest += line;
        if (not appendNext)
            return true;
    }

    return dest.length();
}
//
//
//        bool literalBackslash = false;              // last char is literal
//                                                    // backslash?
//        if (d_rmComment)
//            literalBackslash = removeComment(line);
//                                                    // process lines ending
//                                                    // in a backslash
//        n_continuations = 0;
//        if (not literalBackslash)
//        {
//            while (size_t lastIdx = line.length())  // as long as there are
//            {                                       // characters
//    
//                --lastIdx;                          // set lastIdx to idx of 
//                                                    // last ch.
//    
//                if (line[lastIdx] != '\\')          // last not \ ?
//                    break;                          // then done here
//                              
//                                                    // got line continuation...
//
//                line.resize(lastIdx);               // erase the last char
//
//                                                    // append the next line
//                n_continuations += append_next(inStream, line);
//            }
//        }
//
//        if (hasContent(line))                       // any contents on this?
//        {
//            removeTrailingBlanks(line);
//
//            if (d_indices)
//                d_index.push_back(d_rawIndex - n_continuations - 1);
//
//            return true;
//        }
//    }
//
//    line.erase();
//    return false;                       // no more lines
//}   

