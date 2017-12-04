/********************************************************************************
** Form generated from reading UI file 'parameters_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERS_WINDOW_H
#define UI_PARAMETERS_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParametersWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnDownload;
    QGroupBox *grpParameterization;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;
    QFormLayout *lytForm;
    QStatusBar *stbMain;

    void setupUi(QMainWindow *ParametersWindow)
    {
        if (ParametersWindow->objectName().isEmpty())
            ParametersWindow->setObjectName(QString::fromUtf8("ParametersWindow"));
        ParametersWindow->resize(455, 223);
        centralwidget = new QWidget(ParametersWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnDownload = new QPushButton(centralwidget);
        btnDownload->setObjectName(QString::fromUtf8("btnDownload"));

        horizontalLayout->addWidget(btnDownload);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        grpParameterization = new QGroupBox(centralwidget);
        grpParameterization->setObjectName(QString::fromUtf8("grpParameterization"));
        verticalLayout = new QVBoxLayout(grpParameterization);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(grpParameterization);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::Panel);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 409, 110));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lytForm = new QFormLayout();
        lytForm->setObjectName(QString::fromUtf8("lytForm"));

        gridLayout_2->addLayout(lytForm, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout->addWidget(scrollArea);


        gridLayout->addWidget(grpParameterization, 0, 0, 1, 1);

        ParametersWindow->setCentralWidget(centralwidget);
        stbMain = new QStatusBar(ParametersWindow);
        stbMain->setObjectName(QString::fromUtf8("stbMain"));
        ParametersWindow->setStatusBar(stbMain);

        retranslateUi(ParametersWindow);

        QMetaObject::connectSlotsByName(ParametersWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ParametersWindow)
    {
        ParametersWindow->setWindowTitle(QApplication::translate("ParametersWindow", "Parameterization", 0, QApplication::UnicodeUTF8));
        btnDownload->setText(QApplication::translate("ParametersWindow", "Download Set to DSP", 0, QApplication::UnicodeUTF8));
        grpParameterization->setTitle(QApplication::translate("ParametersWindow", "Parameterization", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ParametersWindow: public Ui_ParametersWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERS_WINDOW_H
