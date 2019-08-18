#include "svgfileio.h"
#include <QXmlStreamWriter>

#include "sbdocument.h"

SVGFileIO::SVGFileIO()
{
}

QString SVGFileIO::exportFile(QByteArray &buff, SBDocument *doc) const
{
    QXmlStreamWriter xmlStreamWriter(&buff);
    xmlStreamWriter.setAutoFormatting(true);
    xmlStreamWriter.writeStartDocument();
    xmlStreamWriter.writeStartElement("svg");
    QList<SBShape*> shapeList = doc->shapeList();
    int count = shapeList.count();
    for (int i = 0; i < count; ++i)
    {

    }
    xmlStreamWriter.writeEndElement();
    xmlStreamWriter.writeEndDocument();
    return "";
}
