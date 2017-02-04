#-------------------------------------------------
#
# Project created by QtCreator 2015-04-02T20:36:06
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++0x

TARGET = teszt
TEMPLATE = app
VISUAL_PATH = /home/gomor/work/science/Algorithms/sorts/visual
WORKING_DIR_PATH = /home/gomor/work/science/Algorithms/sorts/visual
INCLUDEPATH += $$VISUAL_PATH

SOURCES += 	teszt.cpp\
	        $$WORKING_DIR_PATH/simple_function_x_y_mw.cpp \
    		$$VISUAL_PATH/qcustomplot.cpp

HEADERS  += 	$$WORKING_DIR_PATH/simple_function_x_y_mw.h \
    		$$VISUAL_PATH/qcustomplot.h

FORMS    += 	$$VISUAL_PATH/window.ui
