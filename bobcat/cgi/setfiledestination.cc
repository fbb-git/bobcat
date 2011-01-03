#include "cgi.ih"

void CGI::setFileDestination(std::string const &path, 
                                std::string const &prefix,
                                Create create)
{
    d_filePath = path;
    if (*d_filePath.rbegin() != '/')
        d_filePath += "/";

    Stat destPath(d_filePath);
    
    if (!destPath.isType(Stat::DIRECTORY) && create == CREATE_PATH)
    {
        string::size_type pos = 0;

        while (true)
        {
            pos = path.find('/', pos);
            if 
            (
                pos == string::npos
                ||
                mkdir(path.substr(0, pos).c_str(), 0750)
            )
                break;
            ++pos;                  // skip the directory separator
        }
    }

    if (!destPath.isType(Stat::DIRECTORY))
        throw Errno(1, "FBB::CGI: can't create file destination "
                                                            "directory ") <<
                       destPath.path();

    d_filePrefix = prefix;
}
