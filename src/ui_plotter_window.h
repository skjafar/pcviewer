/********************************************************************************
** Form generated from reading UI file 'plotter_window.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTTER_WINDOW_H
#define UI_PLOTTER_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "view/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_PlotterWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QCustomPlot *plot;
    QGridLayout *lytSettings;
    QPushButton *btnAdd;
    QPushButton *btnSaveData;
    QComboBox *cmbRegisters;
    QPushButton *btnRemove;
    QPushButton *btnSavePNG;
    QGroupBox *grpPlots;
    QGridLayout *gridLayout_3;
    QListWidget *lstPlots;
    QGroupBox *grpTimeSpan;
    QGridLayout *gridLayout;
    QLineEdit *txtTimeSpan;
    QGroupBox *grpYAxis;
    QGridLayout *gridLayout_2;
    QLabel *lblScaleMode;
    QRadioButton *optManual;
    QRadioButton *optZero;
    QLabel *lblRange;
    QRadioButton *optCentered;
    QLabel *lblXAxisCrossPoint;
    QRadioButton *optAutomatic;
    QSlider *sliUnits;
    QPushButton *btnPause;
    QButtonGroup *grpCrossPoint;
    QButtonGroup *grpScaleMode;

    void setupUi(QMainWindow *PlotterWindow)
    {
        if (PlotterWindow->objectName().isEmpty())
            PlotterWindow->setObjectName(QStringLiteral("PlotterWindow"));
        PlotterWindow->resize(690, 377);
        centralwidget = new QWidget(PlotterWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QStringLiteral("plot"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(plot);

        lytSettings = new QGridLayout();
        lytSettings->setObjectName(QStringLiteral("lytSettings"));
        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAdd->setIcon(icon);
        btnAdd->setIconSize(QSize(24, 17));

        lytSettings->addWidget(btnAdd, 1, 1, 1, 1);

        btnSaveData = new QPushButton(centralwidget);
        btnSaveData->setObjectName(QStringLiteral("btnSaveData"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/resources/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSaveData->setIcon(icon1);
        btnSaveData->setIconSize(QSize(24, 17));

        lytSettings->addWidget(btnSaveData, 1, 4, 1, 1);

        cmbRegisters = new QComboBox(centralwidget);
        cmbRegisters->setObjectName(QStringLiteral("cmbRegisters"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cmbRegisters->sizePolicy().hasHeightForWidth());
        cmbRegisters->setSizePolicy(sizePolicy1);

        lytSettings->addWidget(cmbRegisters, 1, 0, 1, 1);

        btnRemove = new QPushButton(centralwidget);
        btnRemove->setObjectName(QStringLiteral("btnRemove"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/resources/images/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemove->setIcon(icon2);
        btnRemove->setIconSize(QSize(24, 17));

        lytSettings->addWidget(btnRemove, 1, 2, 1, 1);

        btnSavePNG = new QPushButton(centralwidget);
        btnSavePNG->setObjectName(QStringLiteral("btnSavePNG"));
        btnSavePNG->setIcon(icon1);
        btnSavePNG->setIconSize(QSize(24, 17));

        lytSettings->addWidget(btnSavePNG, 1, 5, 1, 1);

        grpPlots = new QGroupBox(centralwidget);
        grpPlots->setObjectName(QStringLiteral("grpPlots"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(grpPlots->sizePolicy().hasHeightForWidth());
        grpPlots->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(grpPlots);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(-1, -1, -1, 0);
        lstPlots = new QListWidget(grpPlots);
        lstPlots->setObjectName(QStringLiteral("lstPlots"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lstPlots->sizePolicy().hasHeightForWidth());
        lstPlots->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(lstPlots, 4, 0, 1, 2);

        grpTimeSpan = new QGroupBox(grpPlots);
        grpTimeSpan->setObjectName(QStringLiteral("grpTimeSpan"));
        gridLayout = new QGridLayout(grpTimeSpan);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        txtTimeSpan = new QLineEdit(grpTimeSpan);
        txtTimeSpan->setObjectName(QStringLiteral("txtTimeSpan"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(txtTimeSpan->sizePolicy().hasHeightForWidth());
        txtTimeSpan->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(txtTimeSpan, 0, 0, 1, 1);


        gridLayout_3->addWidget(grpTimeSpan, 4, 2, 1, 1);


        lytSettings->addWidget(grpPlots, 0, 0, 1, 3);

        grpYAxis = new QGroupBox(centralwidget);
        grpYAxis->setObjectName(QStringLiteral("grpYAxis"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(grpYAxis->sizePolicy().hasHeightForWidth());
        grpYAxis->setSizePolicy(sizePolicy5);
        gridLayout_2 = new QGridLayout(grpYAxis);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lblScaleMode = new QLabel(grpYAxis);
        lblScaleMode->setObjectName(QStringLiteral("lblScaleMode"));
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(lblScaleMode->sizePolicy().hasHeightForWidth());
        lblScaleMode->setSizePolicy(sizePolicy6);

        gridLayout_2->addWidget(lblScaleMode, 0, 0, 1, 1);

        optManual = new QRadioButton(grpYAxis);
        grpScaleMode = new QButtonGroup(PlotterWindow);
        grpScaleMode->setObjectName(QStringLiteral("grpScaleMode"));
        grpScaleMode->addButton(optManual);
        optManual->setObjectName(QStringLiteral("optManual"));

        gridLayout_2->addWidget(optManual, 0, 2, 1, 1);

        optZero = new QRadioButton(grpYAxis);
        grpCrossPoint = new QButtonGroup(PlotterWindow);
        grpCrossPoint->setObjectName(QStringLiteral("grpCrossPoint"));
        grpCrossPoint->addButton(optZero);
        optZero->setObjectName(QStringLiteral("optZero"));
        optZero->setEnabled(false);
        optZero->setChecked(true);

        gridLayout_2->addWidget(optZero, 1, 1, 1, 1);

        lblRange = new QLabel(grpYAxis);
        lblRange->setObjectName(QStringLiteral("lblRange"));

        gridLayout_2->addWidget(lblRange, 2, 0, 1, 1);

        optCentered = new QRadioButton(grpYAxis);
        grpCrossPoint->addButton(optCentered);
        optCentered->setObjectName(QStringLiteral("optCentered"));
        optCentered->setEnabled(false);

        gridLayout_2->addWidget(optCentered, 1, 2, 1, 1);

        lblXAxisCrossPoint = new QLabel(grpYAxis);
        lblXAxisCrossPoint->setObjectName(QStringLiteral("lblXAxisCrossPoint"));
        sizePolicy6.setHeightForWidth(lblXAxisCrossPoint->sizePolicy().hasHeightForWidth());
        lblXAxisCrossPoint->setSizePolicy(sizePolicy6);

        gridLayout_2->addWidget(lblXAxisCrossPoint, 1, 0, 1, 1);

        optAutomatic = new QRadioButton(grpYAxis);
        grpScaleMode->addButton(optAutomatic);
        optAutomatic->setObjectName(QStringLiteral("optAutomatic"));
        optAutomatic->setChecked(true);

        gridLayout_2->addWidget(optAutomatic, 0, 1, 1, 1);

        sliUnits = new QSlider(grpYAxis);
        sliUnits->setObjectName(QStringLiteral("sliUnits"));
        sliUnits->setEnabled(false);
        sliUnits->setMinimum(1);
        sliUnits->setMaximum(500);
        sliUnits->setSingleStep(10);
        sliUnits->setPageStep(50);
        sliUnits->setOrientation(Qt::Horizontal);
        sliUnits->setTickPosition(QSlider::TicksBelow);

        gridLayout_2->addWidget(sliUnits, 2, 1, 1, 2);


        lytSettings->addWidget(grpYAxis, 0, 3, 1, 3);

        btnPause = new QPushButton(centralwidget);
        btnPause->setObjectName(QStringLiteral("btnPause"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/resources/images/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPause->setIcon(icon3);
        btnPause->setIconSize(QSize(24, 17));
        btnPause->setCheckable(true);

        lytSettings->addWidget(btnPause, 1, 3, 1, 1);


        verticalLayout->addLayout(lytSettings);

        PlotterWindow->setCentralWidget(centralwidget);

        retranslateUi(PlotterWindow);

        QMetaObject::connectSlotsByName(PlotterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PlotterWindow)
    {
        PlotterWindow->setWindowTitle(QApplication::translate("PlotterWindow", "Plotter", 0));
        btnAdd->setText(QApplication::translate("PlotterWindow", "Add", 0));
        btnSaveData->setText(QApplication::translate("PlotterWindow", "Save Data", 0));
        btnRemove->setText(QApplication::translate("PlotterWindow", "Remove", 0));
        btnSavePNG->setText(QApplication::translate("PlotterWindow", "Save PNG", 0));
        grpPlots->setTitle(QApplication::translate("PlotterWindow", "Plots", 0));
        grpTimeSpan->setTitle(QApplication::translate("PlotterWindow", "Time Span [s]", 0));
        txtTimeSpan->setText(QApplication::translate("PlotterWindow", "50", 0));
        grpYAxis->setTitle(QApplication::translate("PlotterWindow", "Y Axis Settings", 0));
        lblScaleMode->setText(QApplication::translate("PlotterWindow", "Scale Mode", 0));
        optManual->setText(QApplication::translate("PlotterWindow", "Manual", 0));
        optZero->setText(QApplication::translate("PlotterWindow", "Zero", 0));
        lblRange->setText(QApplication::translate("PlotterWindow", "Range", 0));
        optCentered->setText(QApplication::translate("PlotterWindow", "Centered", 0));
        lblXAxisCrossPoint->setText(QApplication::translate("PlotterWindow", "X Axis Cross Point", 0));
        optAutomatic->setText(QApplication::translate("PlotterWindow", "Automatic", 0));
        btnPause->setText(QApplication::translate("PlotterWindow", "Pause", 0));
    } // retranslateUi

};

namespace Ui {
    class PlotterWindow: public Ui_PlotterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTTER_WINDOW_H
