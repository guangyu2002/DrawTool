#include "svgexportio.h"
#include "svgfileio.h"

SBIFileIO *getIFileIO()
{
    return new SVGFileIO();
}
