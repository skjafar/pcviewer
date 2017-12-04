/********************************************************************************
** Form generated from reading UI file 'logger_window.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGER_WINDOW_H
#define UI_LOGGER_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "view/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_LoggerWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCustomPlot *plot;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QPushButton *btnDump;

    void setupUi(QMainWindow *LoggerWindow)
    {
        if (LoggerWindow->objectName().isEmpty())
            LoggerWindow->setObjectName(QStringLiteral("LoggerWindow"));
        LoggerWindow->resize(528, 339);
        centralwidget = new QWidget(LoggerWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QStringLiteral("plot"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);

        gridLayout->addWidget(plot, 0, 0, 1, 3);

        btnStart = new QPushButton(centralwidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setEnabled(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/images/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStart->setIcon(icon);
        btnStart->setIconSize(QSize(24, 17));

        gridLayout->addWidget(btnStart, 1, 0, 1, 1);

        btnStop = new QPushButton(centralwidget);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/resources/images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop->setIcon(icon1);
        btnStop->setIconSize(QSize(24, 17));

        gridLayout->addWidget(btnStop, 1, 1, 1, 1);

        btnDump = new QPushButton(centralwidget);
        btnDump->setObjectName(QStringLiteral("btnDump"));
        btnDump->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/resources/images/plot.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDump->setIcon(icon2);
        btnDump->setIconSize(QSize(24, 17));

        gridLayout->addWidget(btnDump, 1, 2, 1, 1);

        LoggerWindow->setCentralWidget(centralwidget);

        retranslateUi(LoggerWindow);

        QMetaObject::connectSlotsByName(LoggerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoggerWindow)
    {
        LoggerWindow->setWindowTitle(QApplication::translate("LoggerWindow", "Logger", 0));
        btnStart->setText(QApplication::translate("LoggerWindow", "Start", 0));
        btnStop->setText(QApplication::translate("LoggerWindow", "Stop", 0));
        btnDump->setText(QApplication::translate("LoggerWindow", "Plot Log", 0));
    } // retranslateUi

};

namespace Ui {
    class LoggerWindow: public Ui_LoggerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGER_WINDOW_H
