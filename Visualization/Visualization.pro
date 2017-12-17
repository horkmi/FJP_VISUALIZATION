QT += widgets core

TEMPLATE = app
TARGET = Visualization
INCLUDEPATH += .
CONFIG += console

QMAKE_CXXFLAGS += -std=c++0x -pthread 
LIBS += -pthread

HEADERS += src/gui/*.hpp src/input/*.hpp
SOURCES += src/*.cpp src/gui/*.cpp src/input/*.cpp
