/********************************************************************************
** Form generated from reading UI file 'waveform_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEFORM_WINDOW_H
#define UI_WAVEFORM_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "view/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_WaveformWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QCustomPlot *plot;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *lstPlots;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *cmbRegisters;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QGroupBox *grpYAxis;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QRadioButton *optAutomatic;
    QRadioButton *optManual;
    QSlider *sliUnits;
    QLabel *lblRange;
    QLabel *label_2;
    QRadioButton *optCentered;
    QRadioButton *optZero;
    QSpacerItem *verticalSpacer;
    QButtonGroup *grpScaleMode;
    QButtonGroup *grpCrossPoint;

    void setupUi(QMainWindow *WaveformWindow)
    {
        if (WaveformWindow->objectName().isEmpty())
            WaveformWindow->setObjectName(QString::fromUtf8("WaveformWindow"));
        WaveformWindow->resize(689, 401);
        centralwidget = new QWidget(WaveformWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);

        gridLayout->addWidget(plot, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lstPlots = new QListWidget(groupBox);
        lstPlots->setObjectName(QString::fromUtf8("lstPlots"));

        verticalLayout->addWidget(lstPlots);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cmbRegisters = new QComboBox(groupBox);
        cmbRegisters->setObjectName(QString::fromUtf8("cmbRegisters"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cmbRegisters->sizePolicy().hasHeightForWidth());
        cmbRegisters->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(cmbRegisters);

        btnAdd = new QPushButton(groupBox);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        horizontalLayout_2->addWidget(btnAdd);

        btnRemove = new QPushButton(groupBox);
        btnRemove->setObjectName(QString::fromUtf8("btnRemove"));

        horizontalLayout_2->addWidget(btnRemove);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addWidget(groupBox);

        grpYAxis = new QGroupBox(centralwidget);
        grpYAxis->setObjectName(QString::fromUtf8("grpYAxis"));
        sizePolicy1.setHeightForWidth(grpYAxis->sizePolicy().hasHeightForWidth());
        grpYAxis->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(grpYAxis);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(grpYAxis);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        optAutomatic = new QRadioButton(grpYAxis);
        grpScaleMode = new QButtonGroup(WaveformWindow);
        grpScaleMode->setObjectName(QString::fromUtf8("grpScaleMode"));
        grpScaleMode->addButton(optAutomatic);
        optAutomatic->setObjectName(QString::fromUtf8("optAutomatic"));
        optAutomatic->setChecked(true);

        gridLayout_2->addWidget(optAutomatic, 0, 1, 1, 1);

        optManual = new QRadioButton(grpYAxis);
        grpScaleMode->addButton(optManual);
        optManual->setObjectName(QString::fromUtf8("optManual"));

        gridLayout_2->addWidget(optManual, 0, 2, 1, 1);

        sliUnits = new QSlider(grpYAxis);
        sliUnits->setObjectName(QString::fromUtf8("sliUnits"));
        sliUnits->setEnabled(false);
        sliUnits->setMinimum(1);
        sliUnits->setMaximum(500);
        sliUnits->setSingleStep(10);
        sliUnits->setPageStep(50);
        sliUnits->setOrientation(Qt::Horizontal);
        sliUnits->setTickPosition(QSlider::TicksBelow);

        gridLayout_2->addWidget(sliUnits, 2, 1, 1, 2);

        lblRange = new QLabel(grpYAxis);
        lblRange->setObjectName(QString::fromUtf8("lblRange"));

        gridLayout_2->addWidget(lblRange, 2, 0, 1, 1);

        label_2 = new QLabel(grpYAxis);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        optCentered = new QRadioButton(grpYAxis);
        grpCrossPoint = new QButtonGroup(WaveformWindow);
        grpCrossPoint->setObjectName(QString::fromUtf8("grpCrossPoint"));
        grpCrossPoint->addButton(optCentered);
        optCentered->setObjectName(QString::fromUtf8("optCentered"));
        optCentered->setEnabled(false);

        gridLayout_2->addWidget(optCentered, 1, 2, 1, 1);

        optZero = new QRadioButton(grpYAxis);
        grpCrossPoint->addButton(optZero);
        optZero->setObjectName(QString::fromUtf8("optZero"));
        optZero->setEnabled(false);
        optZero->setChecked(true);

        gridLayout_2->addWidget(optZero, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 3);


        horizontalLayout->addWidget(grpYAxis);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        WaveformWindow->setCentralWidget(centralwidget);

        retranslateUi(WaveformWindow);

        QMetaObject::connectSlotsByName(WaveformWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WaveformWindow)
    {
        WaveformWindow->setWindowTitle(QApplication::translate("WaveformWindow", "Plot", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("WaveformWindow", "Plots", 0, QApplication::UnicodeUTF8));
        btnAdd->setText(QApplication::translate("WaveformWindow", "Add", 0, QApplication::UnicodeUTF8));
        btnRemove->setText(QApplication::translate("WaveformWindow", "Remove", 0, QApplication::UnicodeUTF8));
        grpYAxis->setTitle(QApplication::translate("WaveformWindow", "Y Axis Settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WaveformWindow", "Scale Mode", 0, QApplication::UnicodeUTF8));
        optAutomatic->setText(QApplication::translate("WaveformWindow", "Automatic", 0, QApplication::UnicodeUTF8));
        optManual->setText(QApplication::translate("WaveformWindow", "Manual", 0, QApplication::UnicodeUTF8));
        lblRange->setText(QApplication::translate("WaveformWindow", "Range", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WaveformWindow", "X Axis Cross Point", 0, QApplication::UnicodeUTF8));
        optCentered->setText(QApplication::translate("WaveformWindow", "Centered", 0, QApplication::UnicodeUTF8));
        optZero->setText(QApplication::translate("WaveformWindow", "Zero", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WaveformWindow: public Ui_WaveformWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEFORM_WINDOW_H
