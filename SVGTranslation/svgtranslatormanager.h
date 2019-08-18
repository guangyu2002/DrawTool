/**********************************************
 * 创建时间：2019.08.06
 * 作者：guangyu
 * 说明：svg模块转换管理类
 * 修改记录：
***********************************************/

#ifndef SVGTRANSLATORMANAGER_H
#define SVGTRANSLATORMANAGER_H

class SBShape;
class SVGTranslatorManager
{
public:
    SVGTranslatorManager();

    static void exportShape(SBShape *shape);

};

#endif // SVGTRANSLATORMANAGER_H
