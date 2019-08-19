#include "svgfileio.h"
#include "svgtranslatormanager.h"

#include "sbdocument.h"

SVGFileIO::SVGFileIO()
{
}

QString SVGFileIO::exportFile(QByteArray &buff, SBDocument *doc) const
{
    return SVGTranslatorManager::getInstance().exportSvg(buff, doc);
}
