#include "iou.ih"

bool bobcatVerify(char const *className)
{
    cerr << 
    "\n"
    "****************************\n"
    "Before Bobcat version 1.20.0 " << className << "constructor(s)\n"
    "threw an exception when they could not properly be completed\n"
    "This is inappropriate as constructors should not throw exceptions.\n"
    "From Bobcat 1.20.0 and beyond the member '" << className << 
                                                            "::verify()'\n"
    "should be used to verify the proper completion of such " << 
                                                            className << "\n"
    "constructors.\n"
    "Consult the " << className << "(3bobcat) man-page for details\n"
    "****************************\n"
    "\n";
    return true;
}
