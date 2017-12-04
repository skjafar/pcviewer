/********************************************************************************
** Form generated from reading UI file 'waveform_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEFORM_WIDGET_H
#define UI_WAVEFORM_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "view/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_WaveformWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *lblSize;
    QLabel *lblFinal;
    QCustomPlot *plot;
    QLineEdit *txtPeriod;
    QLineEdit *txtSize;
    QLineEdit *txtFinal;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPlot;
    QPushButton *btnSave;
    QPushButton *btnUpload;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *lblPeriod;
    QLabel *label_4;
    QLabel *lblDelay;
    QLineEdit *txtDelay;

    void setupUi(QWidget *WaveformWidget)
    {
        if (WaveformWidget->objectName().isEmpty())
            WaveformWidget->setObjectName(QStringLiteral("WaveformWidget"));
        WaveformWidget->resize(486, 435);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WaveformWidget->sizePolicy().hasHeightForWidth());
        WaveformWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(WaveformWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        label = new QLabel(WaveformWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        lblSize = new QLabel(WaveformWidget);
        lblSize->setObjectName(QStringLiteral("lblSize"));
        lblSize->setMinimumSize(QSize(40, 0));
        lblSize->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblSize, 1, 1, 1, 1);

        lblFinal = new QLabel(WaveformWidget);
        lblFinal->setObjectName(QStringLiteral("lblFinal"));
        lblFinal->setMinimumSize(QSize(40, 0));
        lblFinal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblFinal, 3, 1, 1, 1);

        plot = new QCustomPlot(WaveformWidget);
        plot->setObjectName(QStringLiteral("plot"));
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);
        plot->setMinimumSize(QSize(200, 200));

        gridLayout->addWidget(plot, 0, 0, 1, 5);

        txtPeriod = new QLineEdit(WaveformWidget);
        txtPeriod->setObjectName(QStringLiteral("txtPeriod"));

        gridLayout->addWidget(txtPeriod, 2, 3, 1, 1);

        txtSize = new QLineEdit(WaveformWidget);
        txtSize->setObjectName(QStringLiteral("txtSize"));

        gridLayout->addWidget(txtSize, 1, 3, 1, 1);

        txtFinal = new QLineEdit(WaveformWidget);
        txtFinal->setObjectName(QStringLiteral("txtFinal"));

        gridLayout->addWidget(txtFinal, 3, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnPlot = new QPushButton(WaveformWidget);
        btnPlot->setObjectName(QStringLiteral("btnPlot"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/images/plot.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlot->setIcon(icon);
        btnPlot->setIconSize(QSize(24, 17));

        horizontalLayout->addWidget(btnPlot);

        btnSave = new QPushButton(WaveformWidget);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/resources/images/download.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSave->setIcon(icon1);
        btnSave->setIconSize(QSize(24, 17));

        horizontalLayout->addWidget(btnSave);

        btnUpload = new QPushButton(WaveformWidget);
        btnUpload->setObjectName(QStringLiteral("btnUpload"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/resources/images/upload.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnUpload->setIcon(icon2);
        btnUpload->setIconSize(QSize(24, 17));

        horizontalLayout->addWidget(btnUpload);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 5);

        label_2 = new QLabel(WaveformWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_3 = new QLabel(WaveformWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lblPeriod = new QLabel(WaveformWidget);
        lblPeriod->setObjectName(QStringLiteral("lblPeriod"));
        lblPeriod->setMinimumSize(QSize(40, 0));
        lblPeriod->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblPeriod, 2, 1, 1, 1);

        label_4 = new QLabel(WaveformWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        lblDelay = new QLabel(WaveformWidget);
        lblDelay->setObjectName(QStringLiteral("lblDelay"));
        lblDelay->setMinimumSize(QSize(40, 0));
        lblDelay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblDelay, 4, 1, 1, 1);

        txtDelay = new QLineEdit(WaveformWidget);
        txtDelay->setObjectName(QStringLiteral("txtDelay"));

        gridLayout->addWidget(txtDelay, 4, 3, 1, 1);

        QWidget::setTabOrder(txtSize, txtPeriod);
        QWidget::setTabOrder(txtPeriod, txtFinal);
        QWidget::setTabOrder(txtFinal, btnPlot);
        QWidget::setTabOrder(btnPlot, btnUpload);

        retranslateUi(WaveformWidget);

        QMetaObject::connectSlotsByName(WaveformWidget);
    } // setupUi

    void retranslateUi(QWidget *WaveformWidget)
    {
        WaveformWidget->setWindowTitle(QApplication::translate("WaveformWidget", "Form", 0));
        label->setText(QApplication::translate("WaveformWidget", "Period:", 0));
        lblSize->setText(QApplication::translate("WaveformWidget", "N/A", 0));
        lblFinal->setText(QApplication::translate("WaveformWidget", "N/A", 0));
        btnPlot->setText(QApplication::translate("WaveformWidget", "Plot Waveform", 0));
        btnSave->setText(QApplication::translate("WaveformWidget", "Download to File", 0));
        btnUpload->setText(QApplication::translate("WaveformWidget", "Upload to Flash", 0));
        label_2->setText(QApplication::translate("WaveformWidget", "Final:", 0));
        label_3->setText(QApplication::translate("WaveformWidget", "Size:", 0));
        lblPeriod->setText(QApplication::translate("WaveformWidget", "N/A", 0));
        label_4->setText(QApplication::translate("WaveformWidget", "Delay:", 0));
        lblDelay->setText(QApplication::translate("WaveformWidget", "N/A", 0));
    } // retranslateUi

};

namespace Ui {
    class WaveformWidget: public Ui_WaveformWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEFORM_WIDGET_H
