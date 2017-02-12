#include "exception.ih"

size_t Exception::protection(std::string const &name, size_t protect,
                           Protection type)
{
    if (protect > 0777)
        throw Exception{} << "Protection for `" << name << "' "
                             "may not exceed 0777 (requested: 0" << oct <<
                                protect << dec << ')';

    struct stat statbuf;
    
                            // no: create it with the requested protection
    if (stat(name.c_str(), &statbuf) != 0)                          // bits
    {                           
        if (errno != ENOENT)    // stat error, but not non-existing file
            throw Exception{} << "Cannot obtain details about `" << name <<
                                                                        '\'';
        int fd = ::open(name.c_str(), O_CREAT, protect);

        if (fd < 0)
            throw Exception{} << "Can't create 0" << oct << protect << 
                                 dec << ' ' << name;
        close(fd);

        return protect;
    }

    size_t mode = statbuf.st_mode & 07777;  // get the actual mode

    if (type == EQUAL && mode != protect)
        throw Exception{} << "Protection of `" << name << "' (0" << oct <<
                            mode << ") differs from required 0" << 
                            protect;
    return mode;
}
