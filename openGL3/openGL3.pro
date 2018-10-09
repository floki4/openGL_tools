TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

INCLUDEPATH += -L/usr/include
#INCLUDEPATH += -L/usr/include/fbx/

LIBS += -L/usr/lib/i386-linux-gnu -lGL -lGLEW -lglut -lGLU

#LIBS += -L/usr/lib/i386-linux-gnu/fbx/libfbxsdk.a

LIBS += -L/usr/lib -lSOIL

HEADERS += \
    game.h \
    core/window.h \
    core/image.h \
    core/sprite.h \
    objects/fon.h \
    core/camera.h \
    sys/xml.h \
    sys/str.h \
    sys/fileworker.h \
    primitives/point.h \
    primitives/peretvorenia.h \
    core/inc.h \
    core/light.h \
    core/matrix.h \
    export/objexporter.h \
    export/fbxexporter.h \
    core/aobject.h \
    sys/print.h \
    sys/xml/circle.h \
    primitives/item.h


DISTFILES +=
