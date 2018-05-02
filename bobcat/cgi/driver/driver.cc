#include "main.ih"

void showParam(CGI::MapStringVector::value_type const &mapValue)
{
    cout << "Param: " << mapValue.first << '\n';

    for (auto &str: mapValue.second)
        cout << "    " << CGI::dos2unix(str) << "\n"
            "    ";

    cout << '\n';
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("evhm:", argc, argv);

    // usage and version are in the source archive in .../cgi/driver
    // arg.versionHelp(usage, version, 2);

    ifstream in(arg[0]);
    string line;
    while (getline(in, line))
    {
        size_t pos = line.find('=');

        if (pos == string::npos)
            continue;
                            // set environment vars simulating
                            // a GET form
        if (setenv(line.substr(0, pos).c_str(),     
               line.substr(pos + 1).c_str(), true) == 0)
        {
            if (arg.option('e'))
                cout << line.substr(0, pos).c_str() << '=' <<
                       line.substr(pos + 1).c_str() << '\n';
        }
        else
            cout << "FAILED: setenv " << line << '\n';
    }

    CGI cgi(false);             // chars are not escaped

    cgi << arg[1];

    if (arg.option(&line, 'm'))
        cgi.setMaxUploadSize(A2x(line), *line.rbegin());

    cout << "Max upload size (b): " << cgi.maxUploadSize() << '\n';

    CGI::Method method = cgi.method();

    cout << "To escape:\n" << 
            cgi << "\n"
            "Method: " << (method == CGI::GET ? "GET" : "POST") << 
            '\n';

    cout << "Query string: " << cgi.query() << '\n';

    cout << "Submit string: `" << cgi.param1("submit") << "'\n";

    for (auto &mapElement: cgi)
        showParam(mapElement);

    cout << "END OF PROGRAM\n";
}
catch (exception const &err)
{
    cout << err.what() << '\n';
    return 1;
}
catch (...)
{
    return 1;
}
