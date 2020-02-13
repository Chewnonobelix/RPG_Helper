QT += gui core widgets network xml xmlpatterns testlib

CONFIG += qt console warn_on depend_includepath testcase c++17
CONFIG -= app_bundle

TEMPLATE = app


TEMPLATE = app

SOURCES += \
    main.cpp \
    testobject.cpp \
    testweapon.cpp

HEADERS += \
    testobject.h \
    testweapon.h

INCLUDEPATH = $$PWD\..\Bestiary
DEPENDPATH = $$OUT_PWD\..\Bestiary
LIBS = -L$$OUT_PWD\..\Bestiary -lBestiary

include(../../config.pro)
