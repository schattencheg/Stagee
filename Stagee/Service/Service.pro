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
    SolverNewtone.h \
    Fixed.h \
    decimal.h \
    decimal_.h

win32: {
    LIBS += -lwsock32 \
            -lws2_32 \
            //-L"../../../boost_mingw_5_10_0/lib"
            -L"d:/boost_mingw_5_10_0/libs"
    INCLUDEPATH +=  //"../../../boost_mingw_5_10_0" \
                    //"../../../boost_mingw_5_10_0/include"
                    "d:/boost_mingw_5_10_0/include/boost-1_66"
}
