#-------------------------------------------------
#
# Project created by QtCreator 2014-11-20T12:38:57
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = pcviewer
TEMPLATE = app

SOURCES += \
    model/communicator.cpp \
    model/request.cpp \
    model/registers_map.cpp \
    model/poll_group.cpp \
    model/register.cpp \
    model/register_poll.cpp \
    model/block_request.cpp \
    model/register_request.cpp \
    model/block_request_machine.cpp \
    model/block.cpp \
    model/blocks_map.cpp \
    model/parameter_set.cpp \
    model/card_scanner.cpp \
    model/faults_map.cpp \
    model/global_state_machine.cpp \
    view/register_widget.cpp \
    view/registers_window.cpp \
    view/qcustomplot.cpp \
    view/scanner_window.cpp \
    view/logger_window.cpp \
    view/plotter_window.cpp \
    view/waveforms_window.cpp \
    view/waveform_widget.cpp \
    view/faults_widget.cpp \
    view/faults_window.cpp \
    view/main_window.cpp \
    common.cpp \
    main.cpp \
    view/dpc_faults_window.cpp \
    view/combined_waveform_widget.cpp

HEADERS  += \
    model/communicator.h \
    model/request.h \
    model/registers_map.h \
    model/register.h \
    model/register_poll.h \
    model/poll_group.h \
    model/block_request.h \
    model/register_request.h \
    model/block_request_machine.h \
    model/blocks_map.h \
    model/block.h \
    model/parameter_set.h \
    model/card_scanner.h \
    model/faults_map.h \
    model/global_state_machine.h \
    view/register_widget.h \
    view/registers_window.h \
    view/qcustomplot.h \
    view/scanner_window.h \
    view/logger_window.h \
    view/plotter_window.h \
    view/waveforms_window.h \
    view/waveform_widget.h \
    view/faults_widget.h \
    view/faults_window.h \
    view/main_window.h \
    data/data.h \
    common.h \
    view/dpc_faults_window.h \
    view/combined_waveform_widget.h

FORMS    += \
    view/registers_window.ui \
    view/scanner_window.ui \
    view/logger_window.ui \
    view/plotter_window.ui \
    view/waveforms_window.ui \
    view/waveform_widget.ui \
    view/faults_widget.ui \
    view/faults_window.ui \
    view/main_window.ui \
    view/register_widget.ui \
    view/dpc_faults_window.ui \
    view/combined_waveform_widget.ui

QMAKE_CXXFLAGS += -std=c++0x

RESOURCES += \
    resources.qrc

RC_ICONS += \
    resources/images/pcviewer.ico
