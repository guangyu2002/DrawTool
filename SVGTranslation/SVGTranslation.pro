#-------------------------------------------------
#
# Project created by QtCreator 2019-08-16T15:21:13
#
#-------------------------------------------------

win32:CONFIG(release, debug|release): TARGET = SVGTranslation
else:win32:CONFIG(debug, debug|release): TARGET = SVGTranslationd
else:unix: TARGET = SVGTranslation

TEMPLATE = lib

DEFINES += SVGTRANSLATION_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        svgexportio.cpp \
        svgfileio.cpp \
        svglinetranlation.cpp \
        svgrecttranlation.cpp \
        svgsimpleshapetranslation.cpp \
        svgtranlationbase.cpp \
        svgtranslatormanager.cpp

HEADERS += \
        svgexportio.h \
        svgfileio.h \
        svglinetranlation.h \
        svgrecttranlation.h \
        svgsimpleshapetranslation.h \
        svgtranlationbase.h \
        svgtranslation_global.h  \
        svgtranslatormanager.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build/release/ -lSBShape
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build/debug/ -lSBShaped
else:unix: LIBS += -L$$PWD/../build/ -lSBShape

INCLUDEPATH += $$PWD/../SBShape
DEPENDPATH += $$PWD/../SBShape
