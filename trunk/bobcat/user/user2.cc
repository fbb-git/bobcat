#include "user.ih"

User::User(User &&tmp)
:
    d_name( move(tmp.d_name) ),
    d_password( move(tmp.d_password) ),
    d_realname( move(tmp.d_realname) ),
    d_homedir( move(tmp.d_homedir) ),
    d_shell( move(tmp.d_shell) ),

    d_uid(tmp.d_uid),
    d_gid(tmp.d_gid)
{}







