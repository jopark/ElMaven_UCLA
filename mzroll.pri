QT += sql core  xml gui

CONFIG += silent exceptions
DEFINES += ZLIB BOOST_IOSTREAMS_NO_LIB

# this is important. Used in mzUtils to make use of correct mkdir function
win32 {
    message("using win32 config")
    DEFINES += MINGW
    DEFINES += WIN32
    DEFINES += CDFPARSER
    LIBS += -lcdfread -lnetcdf -lz -lboost_iostreams-mt
}

unix: {
    INCLUDEPATH += /usr/local/include/ $$top_srcdir/3rdparty/obiwarp
    QMAKE_LFLAGS += -L/usr/local/lib/ -L$$top_builddir/libs/
    LIBS += -lErrorHandling -lobiwarp -lboost_iostreams
}

!isEmpty(ON_TRAVIS)|!isEmpty(ON_APPVEYOR) {
    !isEmpty(IS_TRAVIS_PR)|!isEmpty(IS_APPVEYOR_PR) {
        linux|win32 {
            message("linking with gcov")
            QMAKE_LFLAGS += -lgcov --coverage
        }
    }
}

#INSTALL_LIBDIR = $$(INSTALL_LIBDIR)
#unix {
#  !mac {
#    isEmpty(INSTALL_LIBDIR):INSTALL_LIBDIR=lib
#} }


#INSTALL_PREFIX=$$(DESTDIR)$$INSTALL_PREFIX
#DEFINES += INSTALL_LIBDIR=\\\"$$INSTALL_LIBDIR\\\"



#QMAKE_CXXFLAGS_RELEASE += -O3 -Wall -Wno-sign-compare
#CONFIG += no_keywords
#unix: INCLUDEPATH += /usr/lib/x86_64-linux-gnu/
#unix: LIBS += -lboost_signals
#win32: LIBS += -lboost_signals-mt
#
#QT += core

#
#QMAKE_CC = gcc
#QMAKE_CXX = g++
#
#win32-g++:contains(QMAKE_HOST.arch, x86_64):{
#    DEFINES -= CDFPARSER
#    DEFINES -= ZLIB
#    LIBS -= -lz -lcdfread -lnetcdf
#}
#

mac {
#    message("using mac config")
#    DEFINES += CDFPARSER
#    DEFINES += ZLIB
#    DEFINES += unix
#    LIBS +=  -lz
#    DEFINES += MAC
}

unix {
#   message("using unix config")
#   DEFINES -= LITTLE_ENDIAN
#   DEFINES += UNIX
#   DEFINES += CDFPARSER
#   DEFINES += ZLIB
#   LIBS += -lcdfread  -lz
}


##TOPLEVELDIR = $$PWD
##INCLUDEPATH += $$TOPLEVELDIR
#
#INCLUDEPATH += $$PWD
#win32:INCLUDEPATH += "C:/msys64/mingw64/lib"
#
#LIBS += -L$$OUTPUT_DIR/lib -L$$OUTPUT_DIR/plugin
