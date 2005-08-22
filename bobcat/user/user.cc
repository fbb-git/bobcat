#include "user.ih"

User::User() throw (Errno)
{
    register unsigned uid = getuid();
    struct passwd *pwd;
    
    while ((pwd = getpwent()))
    {
        if (pwd->pw_uid == uid)
        {
            d_name      = pwd->pw_name;
            d_password  = pwd->pw_passwd;
            d_uid       = pwd->pw_uid;
            d_gid       = pwd->pw_gid;
            d_realname  = pwd->pw_gecos;
            d_homedir   = pwd->pw_dir;
            if (*d_homedir.rbegin() != '/')
                d_homedir += '/';
            d_shell     = pwd->pw_shell;
            endpwent();
            return;
        }
    }

    throw Errno() << insertable << 
        "Unable to determine actual user information from `/etc/passwd'" << 
        throwable;
}

