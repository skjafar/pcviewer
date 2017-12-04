/********************************************************************************
** Form generated from reading UI file 'scanner_window.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANNER_WINDOW_H
#define UI_SCANNER_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ScannerWindow
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QComboBox *cmbInterfaces;
    QPushButton *btnScan;
    QLabel *lblInterfaces;
    QListWidget *lstCards;
    QLabel *lblIP;
    QLineEdit *txtIP;
    QFrame *line;
    QPushButton *btnConnect;

    void setupUi(QDialog *ScannerWindow)
    {
        if (ScannerWindow->objectName().isEmpty())
            ScannerWindow->setObjectName(QStringLiteral("ScannerWindow"));
        ScannerWindow->resize(446, 170);
        gridLayout_2 = new QGridLayout(ScannerWindow);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        cmbInterfaces = new QComboBox(ScannerWindow);
        cmbInterfaces->setObjectName(QStringLiteral("cmbInterfaces"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmbInterfaces->sizePolicy().hasHeightForWidth());
        cmbInterfaces->setSizePolicy(sizePolicy);

        gridLayout->addWidget(cmbInterfaces, 0, 1, 1, 1);

        btnScan = new QPushButton(ScannerWindow);
        btnScan->setObjectName(QStringLiteral("btnScan"));
        btnScan->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/images/scan.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnScan->setIcon(icon);
        btnScan->setIconSize(QSize(24, 17));

        gridLayout->addWidget(btnScan, 0, 2, 1, 1);

        lblInterfaces = new QLabel(ScannerWindow);
        lblInterfaces->setObjectName(QStringLiteral("lblInterfaces"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblInterfaces->sizePolicy().hasHeightForWidth());
        lblInterfaces->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lblInterfaces, 0, 0, 1, 1);

        lstCards = new QListWidget(ScannerWindow);
        lstCards->setObjectName(QStringLiteral("lstCards"));

        gridLayout->addWidget(lstCards, 1, 0, 1, 3);

        lblIP = new QLabel(ScannerWindow);
        lblIP->setObjectName(QStringLiteral("lblIP"));

        gridLayout->addWidget(lblIP, 3, 0, 1, 1);

        txtIP = new QLineEdit(ScannerWindow);
        txtIP->setObjectName(QStringLiteral("txtIP"));

        gridLayout->addWidget(txtIP, 3, 1, 1, 1);

        line = new QFrame(ScannerWindow);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 0, 1, 3);

        btnConnect = new QPushButton(ScannerWindow);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/resources/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnConnect->setIcon(icon1);
        btnConnect->setIconSize(QSize(24, 17));

        gridLayout->addWidget(btnConnect, 3, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(ScannerWindow);

        QMetaObject::connectSlotsByName(ScannerWindow);
    } // setupUi

    void retranslateUi(QDialog *ScannerWindow)
    {
        ScannerWindow->setWindowTitle(QApplication::translate("ScannerWindow", "Card Scanner", 0));
        btnScan->setText(QApplication::translate("ScannerWindow", "Scan", 0));
        lblInterfaces->setText(QApplication::translate("ScannerWindow", "Interfaces", 0));
        lblIP->setText(QApplication::translate("ScannerWindow", "Connect to", 0));
        btnConnect->setText(QApplication::translate("ScannerWindow", "Connect", 0));
    } // retranslateUi

};

namespace Ui {
    class ScannerWindow: public Ui_ScannerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANNER_WINDOW_H
