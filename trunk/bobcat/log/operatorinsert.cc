#include "log.ih"

ostream &operator<<(ostream &str, LogManipulator manipulator)
{
    switch (manipulator)
    {
        case FATAL:
            str.flush();
        exit(1);    

        case nl:
            str << static_cast<char>(0);    // 0-char is interpreted by
                                            // LogBuffer as '\n', without
        break;                              // timestamp writing request.
    }
    return str;
}
        
