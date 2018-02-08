TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ContDiffFunction.cpp \
    AbstractSolver.cpp \
    Libs/mongoose.c \
    RestServer.cpp \
    RootFinder.cpp \
    Polynome.cpp \
    main.cpp

HEADERS += \
    ContDiffFunction.h \
    AbstractSolver.h \
    Libs/mongoose.h \
    RestServer.h \
    RootFinder.h \
    Polynome.h

win32: {
    LIBS += -lwsock32 \
            -lws2_32
}
