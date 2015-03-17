#-------------------------------------------------
#
# Project created by QtCreator 2014-06-21T00:14:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myTunes
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    library.cpp \
    playlist.cpp \
    player.cpp \
    ../../../Dropbox/soundEngine/musicEngine.cpp

HEADERS  += mainwindow.h \
    musicEngine.h \
    library.h \
    playlist.h \
    player.h

FORMS    += \
    mainwindow.ui \
    player.ui

OTHER_FILES +=

#Below must be written by hand
#LIBS += "musicEngine.o"
#Directory path to external library
LIBS += -L "C:\\SFML-2.1\\lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-audio-d -lsfml-audio-s -lsfml-audio-s-d -lsfml-system -lsfml-system-s -lsfml-system-d
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-audio-d -lsfml-audio-s -lsfml-audio-s-d -lsfml-system -lsfml-system-s -lsfml-system-d

INCLUDEPATH += "C:\\SFML-2.1\\include"
DEPENDPATH += "C:\\SFML-2.1\\include"
