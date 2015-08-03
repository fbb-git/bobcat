#include "cgi.ih"

namespace
{
    char const content_Type[] = "Content-Type: ";
}

void CGI::upload(string *line)
{
    next(line);                     // Content-Type

    if (line->find(content_Type) != 0)
    {
        d_status = "Content-Type not found for file-field " + 
                    d_contentDisposition[1];
        throw false;
    }

    string contentType = line->substr(sizeof(content_Type) - 1); 

    string destName;                // try s_nTries times to find an available
                                    // file
    for (size_t end = d_fileNr + s_nTries; d_fileNr < end; ++d_fileNr)
    {
        destName = d_filePath + d_filePrefix + X2a(d_fileNr).str();
        if (!Stat(destName))        // path does not exist
            break;
    }
    ofstream dest(destName.c_str());
    if (!dest)
    {
        d_status = "Can't open a file to write an uploaded file";
        throw false;
    }

    string previous;
    unique_ptr<char> buffer(new char[s_uploadBlock]);

    next(line);                         // skip the blank line following the
                                        // content-type

    unsigned long long uploadSize = 0;
    while (true)
    {
        cin.getline(buffer.get(), s_uploadBlock);
        size_t nRead = cin.gcount();    // may include the \n, but the \n is
                                        // then stored as 0, since it is
                                        // removed from the input and an 
                                        // \0 is appended to the read line

        if (!nRead)                     // none read: shouldn't happen
        {
            d_status = "multipart/form-data: no end-boundary found";
            throw false;
        }
    
        if (cin.fail())                 // on fail() no \n was encountered
            cin.clear();
        else                            // no fail: change the \0 into \n
            (buffer.get())[nRead - 1] = '\n';

        // the line that was read contains \r\n characters, so a boundary 
        // can only be encountered if nRead exceeds the boundary length
        // if so, and the buffer's boundary length characters are equal to the
        // boundary then a boundary was found.
        // If the boundary is found, then the previously captured line ends in
        // a \r\n, which does not belong to the uploaded file but is added by
        // the browser's form-handling software which is therefore not
        // included in the uploaded file (hence `- 2', below). Then, the
        // boundary is copied to the line parameter and the function returns.
        if 
        (
            nRead > d_boundary.length()
            &&
            d_boundary.compare(0, d_boundary.length(), 
                               buffer.get(), d_boundary.length()) == 0
        )
        {
            uploadSize += previous.length() - 2;
            if (uploadSize <= d_maxUploadSize)
                dest.write(previous.c_str(), previous.length() - 2);

            line->assign(buffer.get(), nRead);
            break;
        }
        
        if (uploadSize <= d_maxUploadSize)
        {
            uploadSize += previous.length();
            dest.write(previous.c_str(), previous.length());
            previous.assign(buffer.get(), nRead);
        }
    }

    // store the info about this file into d_param

    vector<string> &param = d_param[d_contentDisposition[1]];
    param.push_back(escape(destName));
    param.push_back(escape(d_contentFile[1]));
    param.push_back(escape(contentType));
    param.push_back(uploadSize <= d_maxUploadSize ? 
                        "OK"
                    :
                        "truncated");
}


