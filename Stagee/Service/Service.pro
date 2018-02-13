TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ContDiffFunction.cpp \
    AbstractSolver.cpp \
    Libs/mongoose.c \
    RestServer.cpp \
    Polynome.cpp \
    main.cpp \
    Decimal.cpp \
    SolverDichotomy.cpp \
    SolverHorde.cpp \
    SolverNewtone.cpp

HEADERS += \
    ContDiffFunction.h \
    AbstractSolver.h \
    Libs/mongoose.h \
    RestServer.h \
    Polynome.h \
    Decimal.h \
    SolverDichotomy.h \
    SolverHorde.h \
    SolverNewtone.h

win32: {
    LIBS += -lwsock32 \
            -lws2_32
}
