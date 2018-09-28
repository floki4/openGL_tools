TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

INCLUDEPATH += -L/usr/include

LIBS += -L/usr/lib/i386-linux-gnu -lGL -lglfw -lGLEW -lglut -lGLU

LIBS += -L/usr/lib -lSOIL

HEADERS += \
    game.h \
    core/window.h \
    core/object.h \
    core/image.h \
    core/sprite.h \
    objects/fon.h \
    core/camera.h \
    sys/xml.h \
    sys/str.h \
    sys/xml/node.h \
    sys/fileworker.h


DISTFILES +=
