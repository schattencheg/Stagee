TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


INCLUDEPATH += "gtest/include"
INCLUDEPATH += "gtest/"
INCLUDEPATH += "../ServiceTesting"
INCLUDEPATH += "../Service"
INCLUDEPATH += "../Service/Libs"

SOURCES += main.cpp \
    gtest/src/gtest.cc \
    gtest/src/gtest-all.cc \
    gtest/src/gtest-death-test.cc \
    gtest/src/gtest-filepath.cc \
    gtest/src/gtest-port.cc \
    gtest/src/gtest-printers.cc \
    gtest/src/gtest-test-part.cc \
    gtest/src/gtest-typed-test.cc \
    ../Service/Libs/mongoose.c \
    ../Service/Polynome.cpp \
    ../Service/AbstractSolver.cpp \
    ../Service/ContDiffFunction.cpp \
    ../Service/RootFinder.cpp \
    ../Service/RestServer.cpp

HEADERS += \
    ../Service/Libs/mongoose.h \
    ../Service/Polynome.h \
    ../Service/AbstractSolver.h \
    ../Service/ContDiffFunction.h \
    ../Service/RootFinder.h \
    ../Service/RestServer.h

win32: {
    LIBS += -lwsock32 \
            -lws2_32
}

linux: {
    LIBS += -pthread
}
