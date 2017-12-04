/********************************************************************************
** Form generated from reading UI file 'dpc_faults_window.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPC_FAULTS_WINDOW_H
#define UI_DPC_FAULTS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DPC_FAULTS_WINDOW
{
public:
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *lblILOADInterlockLED;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *lblMAGNETInterlockLED;
    QLabel *lblPCOInterlockLED;
    QLabel *lblDCCTInterlockLED;
    QLabel *label_7;
    QLabel *lblESTOPInterlockLED;
    QLabel *lbldIdtInterlockLED;
    QLabel *lblVMONInterlockLED;
    QLabel *label_8;
    QLabel *label_3;
    QLabel *lblIEARTHInterlockLED;
    QLabel *lblPULSInterlockLED;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_5;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *lblTEMPERATUREInterlockLED;
    QLabel *lblERRORInterlockLED;
    QLabel *label_10;
    QLabel *label_11;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QLabel *lblTTYTimeOutWarningLED;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *lbldIdtWarningLED;

    void setupUi(QDialog *DPC_FAULTS_WINDOW)
    {
        if (DPC_FAULTS_WINDOW->objectName().isEmpty())
            DPC_FAULTS_WINDOW->setObjectName(QStringLiteral("DPC_FAULTS_WINDOW"));
        DPC_FAULTS_WINDOW->resize(433, 259);
        groupBox = new QGroupBox(DPC_FAULTS_WINDOW);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 199, 239));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lblILOADInterlockLED = new QLabel(groupBox);
        lblILOADInterlockLED->setObjectName(QStringLiteral("lblILOADInterlockLED"));
        lblILOADInterlockLED->setMaximumSize(QSize(16, 16));
        lblILOADInterlockLED->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/red-off.png")));
        lblILOADInterlockLED->setScaledContents(true);

        gridLayout->addWidget(lblILOADInterlockLED, 4, 0, 1, 1);

        label_1 = new QLabel(groupBox);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setEnabled(true);
        label_1->setSizeIncrement(QSize(1, 1));

        gridLayout->addWidget(label_1, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);
        label_2->setSizeIncrement(QSize(1, 1));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        lblMAGNETInterlockLED = new QLabel(groupBox);
        lblMAGNETInterlockLED->setObjectName(QStringLiteral("lblMAGNETInterlockLED"));
        lblMAGNETInterlockLED->setMaximumSize(QSize(16, 16));
        lblMAGNETInterlockLED->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/red-off.png")));
        lblMAGNETInterlockLED->setScaledContents(true);

        gridLayout->addWidget(lblMAGNETInterlockLED, 7, 0, 1, 1);

        lblPCOInterlockLED = new QLabel(groupBox);
        lblPCOInterlockLED->setObjectName(QStringLiteral("lblPCOInterlockLED"));
        lblPCOInterlockLED->setMaximumSize(QSize(16, 16));
        lblPCOInterlockLED->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/red-off.png")));
        lblPCOInterlockLED->setScaledContents(true);

        gridLayout->addWidget(lblPCOInterlockLED, 2, 0, 1, 1);

        lblDCCTInterlockLED = new QLabel(groupBox);
        lblDCCTInterlockLED->setObjectName(QStringLiteral("lblDCCTInterlockLED"));
        lblDCCTInterlockLED->setMaximumSize(QSize(16, 16));
        lblDCCTInterlockLED->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/red-off.png")));
        lblDCCTInterlockLED->setScaledContents(true);

        gridLayout->addWidget(lblDCCTInterlockLED, 1, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setEnabled(true);
        label_7->setSizeIncrement(QSize(1, 1));

        gridLayout->addWidget(label_7, 6, 1, 1, 1);

        lblESTOPInterlockLED = new QLabel(groupBox);
        lblESTOPInterlockLED->setObjectName(QStringLiteral("lblESTOPInterlockLED"));
        lblESTOPInterlockLED->setMaximumSize(QSize(16, 16));
        lblESTOPInterlockLED->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/red-off.png")));
        lblESTOPInterlockLED->setScaledContents(true);

        gridLayout->addWidget(lblESTOPInterlockLED, 8, 0, 1, 1);

        lbldIdtInterlockLED = new QLabel(groupBox);
        lbldIdtInterlockLED->setObjectName(QStringLiteral("lbldIdtInterlockLED"));
        lbldIdtInterlockLED->setMaximumSize(QSize(16, 16));
        lbldIdtInterlockLED->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/red-off.png")));
        lbldIdtInterlockLED->setScaledContents(true);

        gridLayout->addWidget(lbldIdtInterlockLED, 6, 0, 1, 1);

        lblVMONInterlockLED = new QLabel(groupBox);
        lblVMONInterlockLED->setObjectName(QStringLiteral("lblVMONInterlockLED"));
        lblVMONInterlockLED->setMaximumSize(QSize(16, 16));
        lblVMONInterlockLED->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/red-off.png")));
        lblVMONInterlockLED->setScaledContents(true);

        gridLayout->addWidget(lblVMONInterlockLED, 3, 0, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setEnabled(true);
        label_8->setSizeIncrement(QSize(1, 1));

        gridLayout->addWidget(label_8, 7, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setEnabled(true);
        label_3->setSizeIncrement(QSize(1, 1));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        lblIEARTHInterlockLED = new QLabel(groupBox);
        lblIEARTHInterlockLED->setObjectName(QStringLiteral("lblIEARTHInterlockLED"));
        lblIEARTHInterlockLED->setMaximumSize(QSize(16, 16));
        lblIEARTHInterlockLED->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/red-off.png")));
        lblIEARTHInterlockLED->setScaledContents(true);

        gridLayout->addWidget(lblIEARTHInterlockLED, 5, 0, 1, 1);

        lblPULSInterlockLED = new QLabel(groupBox);
        lblPULSInterlockLED->setObjectName(QStringLiteral("lblPULSInterlockLED"));
        lblPULSInterlockLED->setMaximumSize(QSize(16, 16));
        lblPULSInterlockLED->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/red-off.png")));
        lblPULSInterlockLED->setScaledContents(true);

        gridLayout->addWidget(lblPULSInterlockLED, 0, 0, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setEnabled(true);
        label_9->setSizeIncrement(QSize(1, 1));

        gridLayout->addWidget(label_9, 8, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setEnabled(true);
        label_6->setSizeIncrement(QSize(1, 1));

        gridLayout->addWidget(label_6, 5, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(true);
        label_4->setSizeIncrement(QSize(1, 1));

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setEnabled(true);
        label_5->setSizeIncrement(QSize(1, 1));

        gridLayout->addWidget(label_5, 4, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        groupBox_2 = new QGroupBox(DPC_FAULTS_WINDOW);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(220, 10, 201, 81));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lblTEMPERATUREInterlockLED = new QLabel(groupBox_2);
        lblTEMPERATUREInterlockLED->setObjectName(QStringLiteral("lblTEMPERATUREInterlockLED"));
        lblTEMPERATUREInterlockLED->setMaximumSize(QSize(16, 16));
        lblTEMPERATUREInterlockLED->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/red-off.png")));
        lblTEMPERATUREInterlockLED->setScaledContents(true);

        gridLayout_2->addWidget(lblTEMPERATUREInterlockLED, 1, 0, 1, 1);

        lblERRORInterlockLED = new QLabel(groupBox_2);
        lblERRORInterlockLED->setObjectName(QStringLiteral("lblERRORInterlockLED"));
        lblERRORInterlockLED->setMaximumSize(QSize(16, 16));
        lblERRORInterlockLED->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/red-off.png")));
        lblERRORInterlockLED->setScaledContents(true);

        gridLayout_2->addWidget(lblERRORInterlockLED, 0, 0, 1, 1);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setEnabled(true);
        label_10->setSizeIncrement(QSize(1, 1));

        gridLayout_2->addWidget(label_10, 0, 1, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setEnabled(true);
        label_11->setSizeIncrement(QSize(1, 1));

        gridLayout_2->addWidget(label_11, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        groupBox_3 = new QGroupBox(DPC_FAULTS_WINDOW);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(220, 90, 201, 81));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lblTTYTimeOutWarningLED = new QLabel(groupBox_3);
        lblTTYTimeOutWarningLED->setObjectName(QStringLiteral("lblTTYTimeOutWarningLED"));
        lblTTYTimeOutWarningLED->setMaximumSize(QSize(16, 16));
        lblTTYTimeOutWarningLED->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/red-off.png")));
        lblTTYTimeOutWarningLED->setScaledContents(true);

        gridLayout_3->addWidget(lblTTYTimeOutWarningLED, 0, 0, 1, 1);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setEnabled(true);
        label_12->setSizeIncrement(QSize(1, 1));

        gridLayout_3->addWidget(label_12, 0, 1, 1, 1);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setEnabled(true);
        label_13->setSizeIncrement(QSize(1, 1));

        gridLayout_3->addWidget(label_13, 1, 1, 1, 1);

        lbldIdtWarningLED = new QLabel(groupBox_3);
        lbldIdtWarningLED->setObjectName(QStringLiteral("lbldIdtWarningLED"));
        lbldIdtWarningLED->setMaximumSize(QSize(16, 16));
        lbldIdtWarningLED->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/red-off.png")));
        lbldIdtWarningLED->setScaledContents(true);

        gridLayout_3->addWidget(lbldIdtWarningLED, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);


        retranslateUi(DPC_FAULTS_WINDOW);

        QMetaObject::connectSlotsByName(DPC_FAULTS_WINDOW);
    } // setupUi

    void retranslateUi(QDialog *DPC_FAULTS_WINDOW)
    {
        DPC_FAULTS_WINDOW->setWindowTitle(QApplication::translate("DPC_FAULTS_WINDOW", "DPC Faults", 0));
        groupBox->setTitle(QApplication::translate("DPC_FAULTS_WINDOW", "Fast Interlocks", 0));
        lblILOADInterlockLED->setText(QString());
        label_1->setText(QApplication::translate("DPC_FAULTS_WINDOW", "PULS Power Supply", 0));
        label_2->setText(QApplication::translate("DPC_FAULTS_WINDOW", "DCCT Interlock", 0));
        lblMAGNETInterlockLED->setText(QString());
        lblPCOInterlockLED->setText(QString());
        lblDCCTInterlockLED->setText(QString());
        label_7->setText(QApplication::translate("DPC_FAULTS_WINDOW", "dI/dt", 0));
        lblESTOPInterlockLED->setText(QString());
        lbldIdtInterlockLED->setText(QString());
        lblVMONInterlockLED->setText(QString());
        label_8->setText(QApplication::translate("DPC_FAULTS_WINDOW", "Magnet Interlock", 0));
        label_3->setText(QApplication::translate("DPC_FAULTS_WINDOW", "PCO Fault", 0));
        lblIEARTHInterlockLED->setText(QString());
        lblPULSInterlockLED->setText(QString());
        label_9->setText(QApplication::translate("DPC_FAULTS_WINDOW", "Equipement Fast Stop", 0));
        label_6->setText(QApplication::translate("DPC_FAULTS_WINDOW", "IEARTH Fault", 0));
        label_4->setText(QApplication::translate("DPC_FAULTS_WINDOW", "VMON Fault", 0));
        label_5->setText(QApplication::translate("DPC_FAULTS_WINDOW", "ILOAD Fault", 0));
        groupBox_2->setTitle(QApplication::translate("DPC_FAULTS_WINDOW", "Slow Interlocks", 0));
        lblTEMPERATUREInterlockLED->setText(QString());
        lblERRORInterlockLED->setText(QString());
        label_10->setText(QApplication::translate("DPC_FAULTS_WINDOW", "I Error Interlock", 0));
        label_11->setText(QApplication::translate("DPC_FAULTS_WINDOW", "IDAC Temperature", 0));
        groupBox_3->setTitle(QApplication::translate("DPC_FAULTS_WINDOW", "Warnings", 0));
        lblTTYTimeOutWarningLED->setText(QString());
        label_12->setText(QApplication::translate("DPC_FAULTS_WINDOW", "Serial Comm. Timeout", 0));
        label_13->setText(QApplication::translate("DPC_FAULTS_WINDOW", "dI/dt Exeeded", 0));
        lbldIdtWarningLED->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DPC_FAULTS_WINDOW: public Ui_DPC_FAULTS_WINDOW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPC_FAULTS_WINDOW_H
