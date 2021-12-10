QT       += core widgets
TARGET = CommandGUI
TEMPLATE = app 
SOURCES += main.cpp mainwindow.cpp command.cpp 
HEADERS += mainwindow.h command.h
LIBS += -std=gnu++11 -I/usr/local/Fireurchin/boost/1.76.0/include -L/usr/local/Fireurchin/boost/1.76.0/lib -lboost_thread -lpthread 
INCLUDEPATH += /usr/local/Fireurchin/boost/1.76.0/include
INCLUDEPATH += /usr/local/Fireurchin/boost/1.76.0/lib