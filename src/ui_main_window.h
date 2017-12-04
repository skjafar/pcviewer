/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSettingsEnableWrites;
    QAction *actionParameterizationDownload;
    QAction *actionParameterizationUpload;
    QAction *actionLoggerShow;
    QAction *actionPlotterShow;
    QAction *actionFaultsShow;
    QAction *actionRawRegistersShow;
    QAction *actionWaveformSettings;
    QAction *actionDC_Settings;
    QAction *actionRestartFirmware;
    QAction *actionUpdateDSP;
    QAction *actionUpdateFPGA;
    QAction *actionUpdateNIOS;
    QAction *actionTest;
    QAction *actionStates;
    QAction *actionTune;
    QAction *actionDPCFaultsShow;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *grpDC;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLabel *lblReferenceCurrent;
    QLabel *lblUnits;
    QLineEdit *txtReferenceCurrent;
    QHBoxLayout *lytExpertSettings;
    QPushButton *pushButton;
    QPushButton *btnWaveformSettings;
    QGroupBox *grpWaveform;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *lytArmMode;
    QLabel *label_10;
    QPushButton *btnSemiAutomatic;
    QPushButton *btnAutomatic;
    QPushButton *btnManual;
    QSpacerItem *horizontalSpacer;
    QLabel *label_11;
    QLabel *lblNextWaveform;
    QPushButton *btnSkip;
    QHBoxLayout *lytWaveformControl;
    QPushButton *btnTrigger;
    QPushButton *btnPause;
    QPushButton *btnResume;
    QPushButton *btnStop;
    QHBoxLayout *lytGlobalStateMachine;
    QPushButton *btnOpenloop;
    QPushButton *btnOff;
    QPushButton *btnStandby;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnON;
    QHBoxLayout *lytInterlock;
    QLabel *lblInterlockLED;
    QLabel *label;
    QLabel *lblState;
    QLabel *label_2;
    QLabel *lblILOAD;
    QComboBox *comboMode;
    QPushButton *btnReset;
    QPushButton *btnSendInterlock;
    QMenuBar *menuBar;
    QMenu *menuSettings;
    QMenu *menuParameterization;
    QMenu *menuTools;
    QMenu *menuUpdateFirmware;
    QStatusBar *stbMain;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(693, 334);
        actionSettingsEnableWrites = new QAction(MainWindow);
        actionSettingsEnableWrites->setObjectName(QStringLiteral("actionSettingsEnableWrites"));
        actionSettingsEnableWrites->setCheckable(true);
        actionSettingsEnableWrites->setChecked(true);
        actionParameterizationDownload = new QAction(MainWindow);
        actionParameterizationDownload->setObjectName(QStringLiteral("actionParameterizationDownload"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/images/download.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionParameterizationDownload->setIcon(icon);
        actionParameterizationUpload = new QAction(MainWindow);
        actionParameterizationUpload->setObjectName(QStringLiteral("actionParameterizationUpload"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/resources/images/upload.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionParameterizationUpload->setIcon(icon1);
        actionLoggerShow = new QAction(MainWindow);
        actionLoggerShow->setObjectName(QStringLiteral("actionLoggerShow"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/resources/images/logger.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoggerShow->setIcon(icon2);
        actionPlotterShow = new QAction(MainWindow);
        actionPlotterShow->setObjectName(QStringLiteral("actionPlotterShow"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/resources/images/plot.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlotterShow->setIcon(icon3);
        actionFaultsShow = new QAction(MainWindow);
        actionFaultsShow->setObjectName(QStringLiteral("actionFaultsShow"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/resources/images/interlock.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFaultsShow->setIcon(icon4);
        actionRawRegistersShow = new QAction(MainWindow);
        actionRawRegistersShow->setObjectName(QStringLiteral("actionRawRegistersShow"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/resources/images/registers.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRawRegistersShow->setIcon(icon5);
        actionWaveformSettings = new QAction(MainWindow);
        actionWaveformSettings->setObjectName(QStringLiteral("actionWaveformSettings"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/resources/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWaveformSettings->setIcon(icon6);
        actionDC_Settings = new QAction(MainWindow);
        actionDC_Settings->setObjectName(QStringLiteral("actionDC_Settings"));
        actionDC_Settings->setEnabled(false);
        actionDC_Settings->setIcon(icon6);
        actionRestartFirmware = new QAction(MainWindow);
        actionRestartFirmware->setObjectName(QStringLiteral("actionRestartFirmware"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/resources/images/restart.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRestartFirmware->setIcon(icon7);
        actionUpdateDSP = new QAction(MainWindow);
        actionUpdateDSP->setObjectName(QStringLiteral("actionUpdateDSP"));
        actionUpdateFPGA = new QAction(MainWindow);
        actionUpdateFPGA->setObjectName(QStringLiteral("actionUpdateFPGA"));
        actionUpdateFPGA->setEnabled(false);
        actionUpdateNIOS = new QAction(MainWindow);
        actionUpdateNIOS->setObjectName(QStringLiteral("actionUpdateNIOS"));
        actionUpdateNIOS->setEnabled(false);
        actionTest = new QAction(MainWindow);
        actionTest->setObjectName(QStringLiteral("actionTest"));
        actionStates = new QAction(MainWindow);
        actionStates->setObjectName(QStringLiteral("actionStates"));
        actionTune = new QAction(MainWindow);
        actionTune->setObjectName(QStringLiteral("actionTune"));
        actionDPCFaultsShow = new QAction(MainWindow);
        actionDPCFaultsShow->setObjectName(QStringLiteral("actionDPCFaultsShow"));
        actionDPCFaultsShow->setIcon(icon4);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        grpDC = new QGroupBox(centralwidget);
        grpDC->setObjectName(QStringLiteral("grpDC"));
        grpDC->setStyleSheet(QLatin1String("QGroupBox\n"
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
        horizontalLayout = new QHBoxLayout(grpDC);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_8 = new QLabel(grpDC);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout->addWidget(label_8);

        lblReferenceCurrent = new QLabel(grpDC);
        lblReferenceCurrent->setObjectName(QStringLiteral("lblReferenceCurrent"));
        lblReferenceCurrent->setMinimumSize(QSize(40, 0));
        lblReferenceCurrent->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblReferenceCurrent);

        lblUnits = new QLabel(grpDC);
        lblUnits->setObjectName(QStringLiteral("lblUnits"));

        horizontalLayout->addWidget(lblUnits);

        txtReferenceCurrent = new QLineEdit(grpDC);
        txtReferenceCurrent->setObjectName(QStringLiteral("txtReferenceCurrent"));

        horizontalLayout->addWidget(txtReferenceCurrent);


        gridLayout->addWidget(grpDC, 2, 0, 1, 1);

        lytExpertSettings = new QHBoxLayout();
        lytExpertSettings->setObjectName(QStringLiteral("lytExpertSettings"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setIcon(icon6);
        pushButton->setIconSize(QSize(24, 17));

        lytExpertSettings->addWidget(pushButton);

        btnWaveformSettings = new QPushButton(centralwidget);
        btnWaveformSettings->setObjectName(QStringLiteral("btnWaveformSettings"));
        btnWaveformSettings->setIcon(icon6);
        btnWaveformSettings->setIconSize(QSize(24, 17));

        lytExpertSettings->addWidget(btnWaveformSettings);


        gridLayout->addLayout(lytExpertSettings, 4, 0, 1, 1);

        grpWaveform = new QGroupBox(centralwidget);
        grpWaveform->setObjectName(QStringLiteral("grpWaveform"));
        grpWaveform->setMinimumSize(QSize(0, 100));
        grpWaveform->setStyleSheet(QLatin1String("QGroupBox\n"
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
        verticalLayout_3 = new QVBoxLayout(grpWaveform);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lytArmMode = new QHBoxLayout();
        lytArmMode->setObjectName(QStringLiteral("lytArmMode"));
        label_10 = new QLabel(grpWaveform);
        label_10->setObjectName(QStringLiteral("label_10"));

        lytArmMode->addWidget(label_10);

        btnSemiAutomatic = new QPushButton(grpWaveform);
        btnSemiAutomatic->setObjectName(QStringLiteral("btnSemiAutomatic"));
        btnSemiAutomatic->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnSemiAutomatic->sizePolicy().hasHeightForWidth());
        btnSemiAutomatic->setSizePolicy(sizePolicy);
        btnSemiAutomatic->setIconSize(QSize(24, 17));

        lytArmMode->addWidget(btnSemiAutomatic);

        btnAutomatic = new QPushButton(grpWaveform);
        btnAutomatic->setObjectName(QStringLiteral("btnAutomatic"));
        btnAutomatic->setEnabled(false);
        sizePolicy.setHeightForWidth(btnAutomatic->sizePolicy().hasHeightForWidth());
        btnAutomatic->setSizePolicy(sizePolicy);
        btnAutomatic->setIconSize(QSize(24, 17));

        lytArmMode->addWidget(btnAutomatic);

        btnManual = new QPushButton(grpWaveform);
        btnManual->setObjectName(QStringLiteral("btnManual"));
        btnManual->setEnabled(false);
        sizePolicy.setHeightForWidth(btnManual->sizePolicy().hasHeightForWidth());
        btnManual->setSizePolicy(sizePolicy);
        btnManual->setIconSize(QSize(24, 17));

        lytArmMode->addWidget(btnManual);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lytArmMode->addItem(horizontalSpacer);

        label_11 = new QLabel(grpWaveform);
        label_11->setObjectName(QStringLiteral("label_11"));

        lytArmMode->addWidget(label_11);

        lblNextWaveform = new QLabel(grpWaveform);
        lblNextWaveform->setObjectName(QStringLiteral("lblNextWaveform"));

        lytArmMode->addWidget(lblNextWaveform);

        btnSkip = new QPushButton(grpWaveform);
        btnSkip->setObjectName(QStringLiteral("btnSkip"));
        btnSkip->setEnabled(false);
        sizePolicy.setHeightForWidth(btnSkip->sizePolicy().hasHeightForWidth());
        btnSkip->setSizePolicy(sizePolicy);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/resources/images/skip.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSkip->setIcon(icon8);
        btnSkip->setIconSize(QSize(24, 17));

        lytArmMode->addWidget(btnSkip);


        verticalLayout_3->addLayout(lytArmMode);

        lytWaveformControl = new QHBoxLayout();
        lytWaveformControl->setObjectName(QStringLiteral("lytWaveformControl"));
        btnTrigger = new QPushButton(grpWaveform);
        btnTrigger->setObjectName(QStringLiteral("btnTrigger"));
        btnTrigger->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/resources/images/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTrigger->setIcon(icon9);
        btnTrigger->setIconSize(QSize(24, 17));

        lytWaveformControl->addWidget(btnTrigger);

        btnPause = new QPushButton(grpWaveform);
        btnPause->setObjectName(QStringLiteral("btnPause"));
        btnPause->setEnabled(false);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/resources/images/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPause->setIcon(icon10);
        btnPause->setIconSize(QSize(24, 17));

        lytWaveformControl->addWidget(btnPause);

        btnResume = new QPushButton(grpWaveform);
        btnResume->setObjectName(QStringLiteral("btnResume"));
        btnResume->setEnabled(false);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/resources/images/resume.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnResume->setIcon(icon11);
        btnResume->setIconSize(QSize(24, 17));

        lytWaveformControl->addWidget(btnResume);

        btnStop = new QPushButton(grpWaveform);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setEnabled(false);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/resources/images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop->setIcon(icon12);
        btnStop->setIconSize(QSize(24, 17));

        lytWaveformControl->addWidget(btnStop);


        verticalLayout_3->addLayout(lytWaveformControl);


        gridLayout->addWidget(grpWaveform, 3, 0, 1, 1);

        lytGlobalStateMachine = new QHBoxLayout();
        lytGlobalStateMachine->setObjectName(QStringLiteral("lytGlobalStateMachine"));
        btnOpenloop = new QPushButton(centralwidget);
        btnOpenloop->setObjectName(QStringLiteral("btnOpenloop"));

        lytGlobalStateMachine->addWidget(btnOpenloop);

        btnOff = new QPushButton(centralwidget);
        btnOff->setObjectName(QStringLiteral("btnOff"));
        btnOff->setEnabled(false);
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/resources/images/off.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnOff->setIcon(icon13);
        btnOff->setIconSize(QSize(24, 17));
        btnOff->setCheckable(true);

        lytGlobalStateMachine->addWidget(btnOff);

        btnStandby = new QPushButton(centralwidget);
        btnStandby->setObjectName(QStringLiteral("btnStandby"));
        btnStandby->setEnabled(false);
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/resources/images/standby.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStandby->setIcon(icon14);
        btnStandby->setIconSize(QSize(24, 17));
        btnStandby->setCheckable(true);
        btnStandby->setDefault(false);
        btnStandby->setFlat(false);

        lytGlobalStateMachine->addWidget(btnStandby);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btnON = new QPushButton(centralwidget);
        btnON->setObjectName(QStringLiteral("btnON"));
        btnON->setEnabled(false);
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/resources/images/dc.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnON->setIcon(icon15);
        btnON->setIconSize(QSize(24, 17));
        btnON->setCheckable(true);

        verticalLayout_2->addWidget(btnON);


        lytGlobalStateMachine->addLayout(verticalLayout_2);


        gridLayout->addLayout(lytGlobalStateMachine, 0, 0, 1, 1);

        lytInterlock = new QHBoxLayout();
        lytInterlock->setObjectName(QStringLiteral("lytInterlock"));
        lblInterlockLED = new QLabel(centralwidget);
        lblInterlockLED->setObjectName(QStringLiteral("lblInterlockLED"));
        lblInterlockLED->setMaximumSize(QSize(16, 16));
        lblInterlockLED->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/red-off.png")));
        lblInterlockLED->setScaledContents(true);

        lytInterlock->addWidget(lblInterlockLED);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        lytInterlock->addWidget(label);

        lblState = new QLabel(centralwidget);
        lblState->setObjectName(QStringLiteral("lblState"));
        lblState->setAutoFillBackground(false);
        lblState->setFrameShape(QFrame::Box);

        lytInterlock->addWidget(lblState);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        lytInterlock->addWidget(label_2);

        lblILOAD = new QLabel(centralwidget);
        lblILOAD->setObjectName(QStringLiteral("lblILOAD"));

        lytInterlock->addWidget(lblILOAD);

        comboMode = new QComboBox(centralwidget);
        comboMode->setObjectName(QStringLiteral("comboMode"));

        lytInterlock->addWidget(comboMode);

        btnReset = new QPushButton(centralwidget);
        btnReset->setObjectName(QStringLiteral("btnReset"));
        btnReset->setEnabled(false);
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/resources/images/reset.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnReset->setIcon(icon16);
        btnReset->setIconSize(QSize(24, 17));

        lytInterlock->addWidget(btnReset);

        btnSendInterlock = new QPushButton(centralwidget);
        btnSendInterlock->setObjectName(QStringLiteral("btnSendInterlock"));
        btnSendInterlock->setEnabled(false);
        btnSendInterlock->setIcon(icon4);
        btnSendInterlock->setIconSize(QSize(24, 17));

        lytInterlock->addWidget(btnSendInterlock);


        gridLayout->addLayout(lytInterlock, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 693, 25));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuParameterization = new QMenu(menuBar);
        menuParameterization->setObjectName(QStringLiteral("menuParameterization"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuUpdateFirmware = new QMenu(menuTools);
        menuUpdateFirmware->setObjectName(QStringLiteral("menuUpdateFirmware"));
        MainWindow->setMenuBar(menuBar);
        stbMain = new QStatusBar(MainWindow);
        stbMain->setObjectName(QStringLiteral("stbMain"));
        MainWindow->setStatusBar(stbMain);

        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuParameterization->menuAction());
        menuSettings->addAction(actionSettingsEnableWrites);
        menuParameterization->addAction(actionParameterizationDownload);
        menuParameterization->addAction(actionParameterizationUpload);
        menuTools->addAction(actionRawRegistersShow);
        menuTools->addAction(actionWaveformSettings);
        menuTools->addAction(actionPlotterShow);
        menuTools->addAction(actionLoggerShow);
        menuTools->addAction(actionDPCFaultsShow);
        menuTools->addAction(actionFaultsShow);
        menuTools->addAction(actionTest);
        menuTools->addAction(actionStates);
        menuTools->addAction(actionTune);
        menuTools->addSeparator();
        menuTools->addAction(actionRestartFirmware);
        menuTools->addAction(menuUpdateFirmware->menuAction());
        menuUpdateFirmware->addAction(actionUpdateDSP);
        menuUpdateFirmware->addAction(actionUpdateFPGA);
        menuUpdateFirmware->addAction(actionUpdateNIOS);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Main Control", 0));
        actionSettingsEnableWrites->setText(QApplication::translate("MainWindow", "Enable writes", 0));
        actionParameterizationDownload->setText(QApplication::translate("MainWindow", "Download to File", 0));
        actionParameterizationUpload->setText(QApplication::translate("MainWindow", "Upload to Flash", 0));
        actionLoggerShow->setText(QApplication::translate("MainWindow", "Logger", 0));
        actionPlotterShow->setText(QApplication::translate("MainWindow", "Plotter", 0));
        actionFaultsShow->setText(QApplication::translate("MainWindow", "Faults", 0));
        actionRawRegistersShow->setText(QApplication::translate("MainWindow", "Raw Registers", 0));
        actionWaveformSettings->setText(QApplication::translate("MainWindow", "Waveforms", 0));
        actionDC_Settings->setText(QApplication::translate("MainWindow", "DC Settings", 0));
        actionRestartFirmware->setText(QApplication::translate("MainWindow", "Restart Firmware", 0));
        actionUpdateDSP->setText(QApplication::translate("MainWindow", "DSP", 0));
        actionUpdateFPGA->setText(QApplication::translate("MainWindow", "FPGA", 0));
        actionUpdateNIOS->setText(QApplication::translate("MainWindow", "NIOS", 0));
        actionTest->setText(QApplication::translate("MainWindow", "Test", 0));
        actionStates->setText(QApplication::translate("MainWindow", "States", 0));
        actionTune->setText(QApplication::translate("MainWindow", "Tune", 0));
        actionDPCFaultsShow->setText(QApplication::translate("MainWindow", "DPC Faults", 0));
        grpDC->setTitle(QApplication::translate("MainWindow", "DC Settings", 0));
        label_8->setText(QApplication::translate("MainWindow", "Reference :", 0));
        lblReferenceCurrent->setText(QApplication::translate("MainWindow", "N/A", 0));
        lblUnits->setText(QApplication::translate("MainWindow", "A", 0));
        txtReferenceCurrent->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "DC Settings", 0));
        btnWaveformSettings->setText(QApplication::translate("MainWindow", "Waveform Settings", 0));
        grpWaveform->setTitle(QApplication::translate("MainWindow", "Waveform Settings", 0));
        label_10->setText(QApplication::translate("MainWindow", "Arm Mode:", 0));
        btnSemiAutomatic->setText(QApplication::translate("MainWindow", "SemiAuto", 0));
        btnAutomatic->setText(QApplication::translate("MainWindow", "Automatic", 0));
        btnManual->setText(QApplication::translate("MainWindow", "Manual", 0));
        label_11->setText(QApplication::translate("MainWindow", "Next waveform:", 0));
        lblNextWaveform->setText(QApplication::translate("MainWindow", "Waveform 0", 0));
        btnSkip->setText(QApplication::translate("MainWindow", "Skip", 0));
        btnTrigger->setText(QApplication::translate("MainWindow", "Trigger", 0));
        btnPause->setText(QApplication::translate("MainWindow", "Pause", 0));
        btnResume->setText(QApplication::translate("MainWindow", "Resume", 0));
        btnStop->setText(QApplication::translate("MainWindow", "Stop", 0));
        btnOpenloop->setText(QApplication::translate("MainWindow", "Openloop", 0));
        btnOff->setText(QApplication::translate("MainWindow", "Off", 0));
        btnStandby->setText(QApplication::translate("MainWindow", "Standby", 0));
#ifndef QT_NO_TOOLTIP
        btnON->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>ON</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        btnON->setText(QApplication::translate("MainWindow", "ON", 0));
        lblInterlockLED->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Interlock", 0));
        lblState->setText(QApplication::translate("MainWindow", "N/A", 0));
        label_2->setText(QApplication::translate("MainWindow", "ILOAD=", 0));
        lblILOAD->setText(QApplication::translate("MainWindow", "0 A", 0));
        comboMode->clear();
        comboMode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "DC", 0)
         << QApplication::translate("MainWindow", "Waveform", 0)
        );
#ifndef QT_NO_WHATSTHIS
        comboMode->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>Mode</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        btnReset->setText(QApplication::translate("MainWindow", "Reset", 0));
        btnSendInterlock->setText(QApplication::translate("MainWindow", "Interlock", 0));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", 0));
        menuParameterization->setTitle(QApplication::translate("MainWindow", "Parameterization", 0));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", 0));
        menuUpdateFirmware->setTitle(QApplication::translate("MainWindow", "Update Firmware", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
