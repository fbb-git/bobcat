#include "process.ih"

Process::ExecContext Process::analyzeCommand()
{
                                // split the elements in d_command
    vector<string> elements(split(d_command.begin(), d_command.end()));
        

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




