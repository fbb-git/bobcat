#include "csv.ih"

    // Initialize the CSV object for a fixed number of specifications
    // blanks are ignored, and each specification may be followed by an
    // integral number defining the repeat count for that specification.

CSV::CSV(std::string const &spec, Mode mode)
:
    d_mode(mode)
{
    setSpec(spec);
}




