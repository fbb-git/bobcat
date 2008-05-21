#include "main.ih"

void outstr(string const &str)
{
    cout << CGI::dos2unix(str) << "\n"
            "    ";
}

void showParam(CGI::MapStringVector::value_type const &mapValue)
{
    cout << "Param: " << mapValue.first << "\n"
            "    ";

    FBB::for_each(mapValue.second.begin(), mapValue.second.end(), outstr);
    cout << endl;
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("evhm:", argc, argv);

    arg.versionHelp(usage, version, 2);

    ifstream in(arg[0]);
    string line;
    while (getline(in, line))
    {
        size_t pos = line.find('=');
        if (pos == string::npos)
            continue;
        if (setenv(line.substr(0, pos).c_str(), 
               line.substr(pos + 1).c_str(), true) == 0)
        {
            if (arg.option('e'))
                cout << line.substr(0, pos).c_str() << '=' <<
                       line.substr(pos + 1).c_str() << endl;
        }
        else
            cout << "FAILED: setenv " << line << endl;
    }

    CGI cgi(false);             // by default no escapes

    cgi << arg[1];

    if (arg.option(&line, 'm'))
        cgi.setMaxUploadSize(A2x(line), *line.rbegin());

    cout << "Max upload size (b): " << cgi.maxUploadSize() << endl;

    CGI::Method method = cgi.method();

    cout << "To escape:\n" << 
            cgi << "\n"
            "Method: " << (method == CGI::GET ? "GET" : "POST") <<
            endl;

    cout << "Query string: " << cgi.query() << endl;

    cgi.param("submit");

    FBB::for_each(cgi.begin(), cgi.end(), &showParam);

    cout << "END OF PROGRAM\n";

    return 0;
}
catch (Errno const &err)
{
    cout << err.what() << endl;
    return 1;
}
catch (...)
{
    cerr << "Caught exception\n";

    return 1;
}




