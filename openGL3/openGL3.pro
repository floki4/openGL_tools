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
    sys/xml/node.h \
    sys/fileworker.h \
    primitives/point.h \
    primitives/peretvorenia.h \
    core/inc.h \
    core/light.h \
    core/matrix.h \
    export/objexporter.h \
    export/fbxexporter.h \
    core/aobject.h


DISTFILES +=

unix:!macx: LIBS += -L$$PWD/../../../../../../usr/lib/i386-linux-gnu/fbx/ -lfbxsdk

INCLUDEPATH += $$PWD/../../../../../../usr/include/i386-linux-gnu/fbx
DEPENDPATH += $$PWD/../../../../../../usr/include/i386-linux-gnu/fbx

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../../usr/lib/i386-linux-gnu/fbx/libfbxsdk.so
