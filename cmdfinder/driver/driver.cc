#include <iostream>
#include <string>

#include <bobcat/cmdfinder>

using namespace std;
using namespace FBB;

// Define a class `Command' in which the array s_action defines the
// command-function associations. Command is derived from CmdFinder,
// specifying the prototype of the member functions to be called

class Command: public CmdFinder<bool (Command::*)() const> 
{
    static Entry s_action[];

    bool add() const                       // some member functions
    {
        cout << "add called: command was `" << cmd() << "'\n";
        if (beyond().length())
            cout << "Beyond " << cmd() << " `" << beyond() << "'\n"; 
        return true;
    }
    bool error() const
    {
        cout << "unrecognized command: `" << cmd() << "' called\n" <<
                count() << " matching alternatives found\n";
        return true;
    }
    bool quit() const
    {
        cout << "quit called: quitting this series\n";
        return false;
    }

    public:
        Command();                      // Declare the default constructor

        bool run(std::string const &cmd)    // run a command
        {
            return (this->*findCmd(cmd))(); // execute the command matching
                                            // 'cmd' 
        }
};

// Define command-function associations. Note that the last is given an empty
// command-text. This is not required, a command text could have been
// specified for the last command as well.

Command::Entry Command::s_action[] =
{
    Entry("add",    &Command::add),
    Entry("quit",   &Command::quit),
    Entry("",       &Command::error),
};

// Define the default constructor
Command::Command()                       // Define the default constructor
:                               // Note the use of `FunctionPtr'
    CmdFinder<FunctionPtr>(s_action, s_action + 
                                    sizeof(s_action) / sizeof(Entry))
{}

void run(Command &cmd, char const *descr, size_t mode = 0)
{
    if (mode)
        cmd.setMode(mode);

    cout << "Enter 5 x a command using " << descr << ".\n";
    for (size_t idx = 0; idx++ < 5; )
    {
        cout << "Enter command " << idx << ": ";
        string text;
        getline(cin, text);
        if (!cmd.run(text))     // run a command
            break;
    }
}

int main()
{
    Command cmd;                // define a command

                                // enter 5 commands using the default mode
    run (cmd, "the default mode");
    run (cmd, "abbreviated commands", Command::UNIQUE);
    run (cmd, "abbreviated case-insensitive commands", 
                                   Command::UNIQUE | Command::INSENSITIVE);
    run (cmd, "abbreviated command lines", 
                                   Command::USE_FIRST | Command::UNIQUE);
    run (cmd, "abbreviated case-insensitive command lines", 
                                   Command::USE_FIRST | Command::UNIQUE |
                                                        Command::INSENSITIVE);
    return 0;
}








