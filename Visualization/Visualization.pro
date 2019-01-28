QT += widgets core

TEMPLATE = app
TARGET = Visualization
INCLUDEPATH += .
CONFIG += console

HEADERS += src/inner/*.hpp src/gui/*.hpp src/io/*.hpp
SOURCES += src/*.cpp src/inner/*.cpp src/gui/*.cpp src/io/*.cpp

# Icon
win32:RC_ICONS += img/visualization.ico