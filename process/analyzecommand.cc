#include "process.hh"

Process::ExecContext Process::analyzeCommand()
{
                                // split the elements in d_command
    String::Type type;
    vector<string> elements(String::split(&type, d_command));

    if (type != String::NORMAL)
        throw Exception() << "Process: " << d_command << ": ill-formed";

    ExecContext ec = {0, new char const *[elements.size() + 1]};

    for (auto str: elements)    // copy the elements to ec.args
        ec.argv[ec.argc++] = 
            (new string(str))->c_str();
        // the allocated memory is never returned, but that's OK as the
        // program's execution ends and the args are passed over to the child
        // process. 

    ec.argv[ec.argc] = 0;   // terminate in a null ptr
     
    return ec;
}




