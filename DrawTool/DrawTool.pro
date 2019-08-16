#-------------------------------------------------
#
# Project created by QtCreator 2019-08-06T08:46:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

win32:CONFIG(release, debug|release): TARGET = DrawTool
else:win32:CONFIG(debug, debug|release): TARGET = DrawToold
else:unix: TARGET = DrawTool

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build/release/ -lSVGTranslation
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build/debug/ -lSVGTranslationd
else:unix: LIBS += -L$$PWD/../build/debug/ -lSVGTranslation

INCLUDEPATH += $$PWD/../SVGTranslation
DEPENDPATH += $$PWD/../SVGTranslation

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build/release/ -lSBShape
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build/debug/ -lSBShaped
else:unix: LIBS += -L$$PWD/../build/debug/ -lSBShape

INCLUDEPATH += $$PWD/../SBShape
DEPENDPATH += $$PWD/../SBShape
