/********************************************************************************
** Form generated from reading UI file 'registers_window.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERS_WINDOW_H
#define UI_REGISTERS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistersWindow
{
public:
    QAction *actionEnableWrites;
    QAction *actionParameterSetDownload;
    QAction *actionShowLogger;
    QAction *actionParameterSetUpload;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGroupBox *grpRegisters;
    QGridLayout *gridLayout;
    QVBoxLayout *lytRegisters;
    QPushButton *btnAddRegisters;

    void setupUi(QMainWindow *RegistersWindow)
    {
        if (RegistersWindow->objectName().isEmpty())
            RegistersWindow->setObjectName(QStringLiteral("RegistersWindow"));
        RegistersWindow->resize(522, 75);
        actionEnableWrites = new QAction(RegistersWindow);
        actionEnableWrites->setObjectName(QStringLiteral("actionEnableWrites"));
        actionEnableWrites->setCheckable(true);
        actionEnableWrites->setChecked(true);
        actionParameterSetDownload = new QAction(RegistersWindow);
        actionParameterSetDownload->setObjectName(QStringLiteral("actionParameterSetDownload"));
        actionShowLogger = new QAction(RegistersWindow);
        actionShowLogger->setObjectName(QStringLiteral("actionShowLogger"));
        actionParameterSetUpload = new QAction(RegistersWindow);
        actionParameterSetUpload->setObjectName(QStringLiteral("actionParameterSetUpload"));
        centralWidget = new QWidget(RegistersWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        grpRegisters = new QGroupBox(centralWidget);
        grpRegisters->setObjectName(QStringLiteral("grpRegisters"));
        grpRegisters->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"	border: 1px solid gray;\n"
"	border-radius: 4px;\n"
"	margin-top: 0.5em;\n"
"}\n"
"\n"
"QGroupBox::title\n"
"{\n"
"	subcontrol-origin: margin;\n"
"	left: 10px;\n"
"	padding: 0 3px 0 3px;\n"
"}"));
        grpRegisters->setFlat(false);
        gridLayout = new QGridLayout(grpRegisters);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lytRegisters = new QVBoxLayout();
        lytRegisters->setSpacing(6);
        lytRegisters->setObjectName(QStringLiteral("lytRegisters"));
        lytRegisters->setSizeConstraint(QLayout::SetDefaultConstraint);
        btnAddRegisters = new QPushButton(grpRegisters);
        btnAddRegisters->setObjectName(QStringLiteral("btnAddRegisters"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddRegisters->setIcon(icon);
        btnAddRegisters->setIconSize(QSize(24, 17));

        lytRegisters->addWidget(btnAddRegisters);


        gridLayout->addLayout(lytRegisters, 0, 0, 1, 1);


        gridLayout_3->addWidget(grpRegisters, 0, 0, 1, 1);

        RegistersWindow->setCentralWidget(centralWidget);

        retranslateUi(RegistersWindow);

        QMetaObject::connectSlotsByName(RegistersWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RegistersWindow)
    {
        RegistersWindow->setWindowTitle(QApplication::translate("RegistersWindow", "Raw Registers Control", 0));
        actionEnableWrites->setText(QApplication::translate("RegistersWindow", "Enable writes", 0));
        actionParameterSetDownload->setText(QApplication::translate("RegistersWindow", "Download to File", 0));
        actionShowLogger->setText(QApplication::translate("RegistersWindow", "Show", 0));
        actionParameterSetUpload->setText(QApplication::translate("RegistersWindow", "Upload to Flash", 0));
        grpRegisters->setTitle(QApplication::translate("RegistersWindow", "Registers", 0));
        btnAddRegisters->setText(QApplication::translate("RegistersWindow", "Add register", 0));
    } // retranslateUi

};

namespace Ui {
    class RegistersWindow: public Ui_RegistersWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERS_WINDOW_H
