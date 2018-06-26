######################################################################
# Automatically generated by qmake (2.01a) Mon Jun 11 16:05:26 2018
######################################################################

TEMPLATE = app
TARGET = app.app
DEPENDPATH += . headers src
INCLUDEPATH += . headers
QMAKE_CXXFLAGS *= -std=gnu++11
QT += opengl

# Input
HEADERS += headers/dollars_widget.h \
           headers/gpa_widget.h \
           headers/hobbies_widget.h \
           headers/sat_widget.h \
           headers/window.h \
           headers/flowlayout.h \
           headers/student_selector.h \
           headers/output_widget.h \
           headers/base.h \
           headers/distance_widget.h \
           headers/graphics_widget.h
SOURCES += src/app.cpp \
           src/dollars_widget.cpp \
           src/gpa_widget.cpp \
           src/hobbies_widget.cpp \
           src/sat_widget.cpp \
           src/window.cpp \
           src/flowlayout.cpp \
           src/student_selector.cpp \
           src/output_widget.cpp \
           src/distance_widget.cpp \
           src/graphics_widget.cpp

# Output
DESTDIR=bin #Target file directory
OBJECTS_DIR=generated_files #Intermediate object files directory
MOC_DIR=generated_files #Intermediate moc files directory
