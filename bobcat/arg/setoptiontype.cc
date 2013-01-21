#include "arg.ih"

int Arg__::setOptionType(string const &optString,
                         LongOption const &longOption)
{
    string::size_type pos = optString.find_first_of(longOption.d_optionChar);

    if (pos == string::npos)
        throw Exception(EINVAL) << "Arg__::setOptionType()") <<
                                ": short option `" << 
                                static_cast<char>(longOption.d_optionChar) << 
                                "' not found";

    return optString[pos + 1] == ':' ? Required : None;
}

