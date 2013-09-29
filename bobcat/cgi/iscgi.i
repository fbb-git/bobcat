inline int CGIFSA::iscgi(int ch)
{
    return s_cgi.find(ch) != string::npos;
}
