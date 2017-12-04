/********************************************************************************
** Form generated from reading UI file 'state_machine_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATE_MACHINE_WINDOW_H
#define UI_STATE_MACHINE_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StateMachineWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *lytGlobalStateMachine;
    QPushButton *btnOff;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *btnStandby;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnDC;
    QPushButton *btnWaveform;
    QHBoxLayout *lytInterlock;
    QLabel *lblInterlockLED;
    QLabel *label;
    QPushButton *btnReset;
    QGroupBox *grpDC;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLineEdit *txtIREF;
    QLabel *lblIREF;
    QGroupBox *grpWaveform;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *lytWaveforms;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_17;
    QLabel *label_12;
    QFrame *line;
    QHBoxLayout *lytArmMode;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnAutomatic;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnManual;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *lytWaveformControl;
    QPushButton *btnTrigger;
    QPushButton *btnPause;
    QPushButton *btnResume;
    QPushButton *btnStop;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *lytExpertSettings;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *StateMachineWindow)
    {
        if (StateMachineWindow->objectName().isEmpty())
            StateMachineWindow->setObjectName(QString::fromUtf8("StateMachineWindow"));
        StateMachineWindow->resize(668, 516);
        centralwidget = new QWidget(StateMachineWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lytGlobalStateMachine = new QHBoxLayout();
        lytGlobalStateMachine->setObjectName(QString::fromUtf8("lytGlobalStateMachine"));
        btnOff = new QPushButton(centralwidget);
        btnOff->setObjectName(QString::fromUtf8("btnOff"));
        btnOff->setEnabled(false);
        btnOff->setCheckable(true);

        lytGlobalStateMachine->addWidget(btnOff);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(10, 10));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/arrow-left.png")));
        label_2->setScaledContents(true);

        horizontalLayout_3->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(16777215, 10));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/horizontal.png")));
        label_3->setScaledContents(true);

        horizontalLayout_3->addWidget(label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(10, 10));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/arrow-right.png")));
        label_4->setScaledContents(true);

        horizontalLayout_3->addWidget(label_4);


        lytGlobalStateMachine->addLayout(horizontalLayout_3);

        btnStandby = new QPushButton(centralwidget);
        btnStandby->setObjectName(QString::fromUtf8("btnStandby"));
        btnStandby->setEnabled(false);
        btnStandby->setCheckable(true);
        btnStandby->setDefault(false);
        btnStandby->setFlat(false);

        lytGlobalStateMachine->addWidget(btnStandby);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(10, 10));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/arrow-left.png")));
        label_5->setScaledContents(true);

        horizontalLayout_4->addWidget(label_5);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(16777215, 10));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/horizontal.png")));
        label_6->setScaledContents(true);

        horizontalLayout_4->addWidget(label_6);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(10, 10));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/arrow-right.png")));
        label_7->setScaledContents(true);

        horizontalLayout_4->addWidget(label_7);


        lytGlobalStateMachine->addLayout(horizontalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btnDC = new QPushButton(centralwidget);
        btnDC->setObjectName(QString::fromUtf8("btnDC"));
        btnDC->setEnabled(false);
        btnDC->setCheckable(true);

        verticalLayout_2->addWidget(btnDC);

        btnWaveform = new QPushButton(centralwidget);
        btnWaveform->setObjectName(QString::fromUtf8("btnWaveform"));
        btnWaveform->setEnabled(false);
        btnWaveform->setCheckable(true);

        verticalLayout_2->addWidget(btnWaveform);


        lytGlobalStateMachine->addLayout(verticalLayout_2);


        verticalLayout->addLayout(lytGlobalStateMachine);

        lytInterlock = new QHBoxLayout();
        lytInterlock->setObjectName(QString::fromUtf8("lytInterlock"));
        lblInterlockLED = new QLabel(centralwidget);
        lblInterlockLED->setObjectName(QString::fromUtf8("lblInterlockLED"));
        lblInterlockLED->setMaximumSize(QSize(16, 16));
        lblInterlockLED->setPixmap(QPixmap(QString::fromUtf8(":/resources/images/red-off.png")));
        lblInterlockLED->setScaledContents(true);

        lytInterlock->addWidget(lblInterlockLED);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        lytInterlock->addWidget(label);

        btnReset = new QPushButton(centralwidget);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));
        btnReset->setEnabled(false);

        lytInterlock->addWidget(btnReset);


        verticalLayout->addLayout(lytInterlock);

        grpDC = new QGroupBox(centralwidget);
        grpDC->setObjectName(QString::fromUtf8("grpDC"));
        grpDC->setStyleSheet(QString::fromUtf8("QGroupBox\n"
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
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_8 = new QLabel(grpDC);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        txtIREF = new QLineEdit(grpDC);
        txtIREF->setObjectName(QString::fromUtf8("txtIREF"));

        horizontalLayout->addWidget(txtIREF);

        lblIREF = new QLabel(grpDC);
        lblIREF->setObjectName(QString::fromUtf8("lblIREF"));

        horizontalLayout->addWidget(lblIREF);


        verticalLayout->addWidget(grpDC);

        grpWaveform = new QGroupBox(centralwidget);
        grpWaveform->setObjectName(QString::fromUtf8("grpWaveform"));
        grpWaveform->setMinimumSize(QSize(0, 100));
        grpWaveform->setStyleSheet(QString::fromUtf8("QGroupBox\n"
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
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lytWaveforms = new QGridLayout();
        lytWaveforms->setObjectName(QString::fromUtf8("lytWaveforms"));
        label_13 = new QLabel(grpWaveform);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        lytWaveforms->addWidget(label_13, 0, 2, 1, 1);

        label_14 = new QLabel(grpWaveform);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        lytWaveforms->addWidget(label_14, 0, 3, 1, 1);

        label_17 = new QLabel(grpWaveform);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        lytWaveforms->addWidget(label_17, 1, 0, 1, 1);

        label_12 = new QLabel(grpWaveform);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        lytWaveforms->addWidget(label_12, 0, 1, 1, 1);


        verticalLayout_3->addLayout(lytWaveforms);

        line = new QFrame(grpWaveform);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        lytArmMode = new QHBoxLayout();
        lytArmMode->setObjectName(QString::fromUtf8("lytArmMode"));
        label_10 = new QLabel(grpWaveform);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        lytArmMode->addWidget(label_10);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lytArmMode->addItem(horizontalSpacer_2);

        btnAutomatic = new QPushButton(grpWaveform);
        btnAutomatic->setObjectName(QString::fromUtf8("btnAutomatic"));
        btnAutomatic->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnAutomatic->sizePolicy().hasHeightForWidth());
        btnAutomatic->setSizePolicy(sizePolicy);

        lytArmMode->addWidget(btnAutomatic);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lytArmMode->addItem(horizontalSpacer_5);

        btnManual = new QPushButton(grpWaveform);
        btnManual->setObjectName(QString::fromUtf8("btnManual"));
        btnManual->setEnabled(false);
        sizePolicy.setHeightForWidth(btnManual->sizePolicy().hasHeightForWidth());
        btnManual->setSizePolicy(sizePolicy);

        lytArmMode->addWidget(btnManual);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lytArmMode->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(lytArmMode);

        lytWaveformControl = new QHBoxLayout();
        lytWaveformControl->setObjectName(QString::fromUtf8("lytWaveformControl"));
        btnTrigger = new QPushButton(grpWaveform);
        btnTrigger->setObjectName(QString::fromUtf8("btnTrigger"));
        btnTrigger->setEnabled(false);

        lytWaveformControl->addWidget(btnTrigger);

        btnPause = new QPushButton(grpWaveform);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        btnPause->setEnabled(false);

        lytWaveformControl->addWidget(btnPause);

        btnResume = new QPushButton(grpWaveform);
        btnResume->setObjectName(QString::fromUtf8("btnResume"));
        btnResume->setEnabled(false);

        lytWaveformControl->addWidget(btnResume);

        btnStop = new QPushButton(grpWaveform);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setEnabled(false);

        lytWaveformControl->addWidget(btnStop);


        verticalLayout_3->addLayout(lytWaveformControl);


        verticalLayout->addWidget(grpWaveform);

        verticalSpacer = new QSpacerItem(20, 44, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        lytExpertSettings = new QHBoxLayout();
        lytExpertSettings->setObjectName(QString::fromUtf8("lytExpertSettings"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        lytExpertSettings->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        lytExpertSettings->addWidget(pushButton_2);


        verticalLayout->addLayout(lytExpertSettings);

        StateMachineWindow->setCentralWidget(centralwidget);

        retranslateUi(StateMachineWindow);

        QMetaObject::connectSlotsByName(StateMachineWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StateMachineWindow)
    {
        StateMachineWindow->setWindowTitle(QApplication::translate("StateMachineWindow", "Main Control", 0, QApplication::UnicodeUTF8));
        btnOff->setText(QApplication::translate("StateMachineWindow", "Off", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        btnStandby->setText(QApplication::translate("StateMachineWindow", "Standby", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        btnDC->setText(QApplication::translate("StateMachineWindow", "DC", 0, QApplication::UnicodeUTF8));
        btnWaveform->setText(QApplication::translate("StateMachineWindow", "Waveform", 0, QApplication::UnicodeUTF8));
        lblInterlockLED->setText(QString());
        label->setText(QApplication::translate("StateMachineWindow", "Interlock", 0, QApplication::UnicodeUTF8));
        btnReset->setText(QApplication::translate("StateMachineWindow", "Reset", 0, QApplication::UnicodeUTF8));
        grpDC->setTitle(QApplication::translate("StateMachineWindow", "DC Settings", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("StateMachineWindow", "Reference current", 0, QApplication::UnicodeUTF8));
        txtIREF->setText(QString());
        lblIREF->setText(QApplication::translate("StateMachineWindow", "-", 0, QApplication::UnicodeUTF8));
        grpWaveform->setTitle(QApplication::translate("StateMachineWindow", "Waveform Settings", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("StateMachineWindow", "Gain", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("StateMachineWindow", "Period", 0, QApplication::UnicodeUTF8));
        label_17->setText(QString());
        label_12->setText(QApplication::translate("StateMachineWindow", "Size", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("StateMachineWindow", "Arm Mode", 0, QApplication::UnicodeUTF8));
        btnAutomatic->setText(QApplication::translate("StateMachineWindow", "Automatic", 0, QApplication::UnicodeUTF8));
        btnManual->setText(QApplication::translate("StateMachineWindow", "Manual", 0, QApplication::UnicodeUTF8));
        btnTrigger->setText(QApplication::translate("StateMachineWindow", "Trigger", 0, QApplication::UnicodeUTF8));
        btnPause->setText(QApplication::translate("StateMachineWindow", "Pause", 0, QApplication::UnicodeUTF8));
        btnResume->setText(QApplication::translate("StateMachineWindow", "Resume", 0, QApplication::UnicodeUTF8));
        btnStop->setText(QApplication::translate("StateMachineWindow", "Stop", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("StateMachineWindow", "DC Expert Settings", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("StateMachineWindow", "Waveform Expert Settings", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StateMachineWindow: public Ui_StateMachineWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATE_MACHINE_WINDOW_H
