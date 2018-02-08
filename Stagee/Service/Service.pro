TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ContDiffFunction.cpp \
    Polynome.cpp \
    AbstractSolver.cpp \
    Libs/mongoose.c \
    RestServer.cpp \
    RootFinder.cpp

HEADERS += \
    ContDiffFunction.h \
    Polynome.h \
    AbstractSolver.h \
    Libs/mongoose.h \
    RestServer.h \
    RootFinder.h

win32: {
    LIBS += -lwsock32 \
            -lws2_32
}
