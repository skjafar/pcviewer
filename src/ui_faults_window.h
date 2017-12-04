/********************************************************************************
** Form generated from reading UI file 'faults_window.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAULTS_WINDOW_H
#define UI_FAULTS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaultsWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;

    void setupUi(QMainWindow *FaultsWindow)
    {
        if (FaultsWindow->objectName().isEmpty())
            FaultsWindow->setObjectName(QStringLiteral("FaultsWindow"));
        FaultsWindow->resize(364, 257);
        centralwidget = new QWidget(FaultsWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        FaultsWindow->setCentralWidget(centralwidget);

        retranslateUi(FaultsWindow);

        QMetaObject::connectSlotsByName(FaultsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FaultsWindow)
    {
        FaultsWindow->setWindowTitle(QApplication::translate("FaultsWindow", "System Faults", 0));
    } // retranslateUi

};

namespace Ui {
    class FaultsWindow: public Ui_FaultsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAULTS_WINDOW_H
