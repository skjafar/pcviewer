/********************************************************************************
** Form generated from reading UI file 'waveforms_window.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEFORMS_WINDOW_H
#define UI_WAVEFORMS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaveformsWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QMainWindow *WaveformsWindow)
    {
        if (WaveformsWindow->objectName().isEmpty())
            WaveformsWindow->setObjectName(QStringLiteral("WaveformsWindow"));
        WaveformsWindow->resize(407, 288);
        centralwidget = new QWidget(WaveformsWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

        WaveformsWindow->setCentralWidget(centralwidget);

        retranslateUi(WaveformsWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WaveformsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WaveformsWindow)
    {
        WaveformsWindow->setWindowTitle(QApplication::translate("WaveformsWindow", "Waveforms", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("WaveformsWindow", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("WaveformsWindow", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class WaveformsWindow: public Ui_WaveformsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEFORMS_WINDOW_H
