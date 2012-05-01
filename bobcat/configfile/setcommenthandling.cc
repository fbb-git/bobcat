#include "configfile.ih"

void ConfigFile__::setCommentHandling(Comment type)
{
    d_rmComment = type == RemoveComment;
}

void ConfigFile::setCommentHandling(Comment type)
{
    d_ptr->setCommentHandling(type);
}

