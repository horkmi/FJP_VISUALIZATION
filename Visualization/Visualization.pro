QT += widgets core

TEMPLATE = app
TARGET = Visualization
INCLUDEPATH += .
CONFIG += console

QMAKE_CXXFLAGS += -std=c++0x -pthread 
LIBS += -pthread

HEADERS += src/inner/*.hpp src/gui/*.hpp src/input/*.hpp
SOURCES += src/*.cpp src/inner/*.cpp src/gui/*.cpp src/input/*.cpp
