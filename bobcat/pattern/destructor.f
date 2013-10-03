inline Pattern::Regex::~Regex()
{
    regfree(&d_regex);
}
