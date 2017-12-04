/********************************************************************************
** Form generated from reading UI file 'register_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_WIDGET_H
#define UI_REGISTER_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *txtValue;
    QComboBox *cmbRegisters;
    QLabel *lblRegister;
    QLabel *lblValue;
    QPushButton *btnPlot;

    void setupUi(QWidget *RegisterWidget)
    {
        if (RegisterWidget->objectName().isEmpty())
            RegisterWidget->setObjectName(QStringLiteral("RegisterWidget"));
        RegisterWidget->resize(447, 33);
        gridLayout = new QGridLayout(RegisterWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(1);
        gridLayout->setContentsMargins(-1, 1, -1, 1);
        label = new QLabel(RegisterWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        txtValue = new QLineEdit(RegisterWidget);
        txtValue->setObjectName(QStringLiteral("txtValue"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(txtValue->sizePolicy().hasHeightForWidth());
        txtValue->setSizePolicy(sizePolicy);

        gridLayout->addWidget(txtValue, 0, 4, 1, 1);

        cmbRegisters = new QComboBox(RegisterWidget);
        cmbRegisters->setObjectName(QStringLiteral("cmbRegisters"));
        sizePolicy.setHeightForWidth(cmbRegisters->sizePolicy().hasHeightForWidth());
        cmbRegisters->setSizePolicy(sizePolicy);

        gridLayout->addWidget(cmbRegisters, 0, 2, 1, 1);

        lblRegister = new QLabel(RegisterWidget);
        lblRegister->setObjectName(QStringLiteral("lblRegister"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblRegister->sizePolicy().hasHeightForWidth());
        lblRegister->setSizePolicy(sizePolicy1);
        lblRegister->setMinimumSize(QSize(30, 0));

        gridLayout->addWidget(lblRegister, 0, 1, 1, 1);

        lblValue = new QLabel(RegisterWidget);
        lblValue->setObjectName(QStringLiteral("lblValue"));
        sizePolicy1.setHeightForWidth(lblValue->sizePolicy().hasHeightForWidth());
        lblValue->setSizePolicy(sizePolicy1);
        lblValue->setMinimumSize(QSize(60, 0));
        lblValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lblValue, 0, 3, 1, 1);

        btnPlot = new QPushButton(RegisterWidget);
        btnPlot->setObjectName(QStringLiteral("btnPlot"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/images/plot.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlot->setIcon(icon);
        btnPlot->setIconSize(QSize(24, 17));

        gridLayout->addWidget(btnPlot, 0, 5, 1, 1);


        retranslateUi(RegisterWidget);

        QMetaObject::connectSlotsByName(RegisterWidget);
    } // setupUi

    void retranslateUi(QWidget *RegisterWidget)
    {
        RegisterWidget->setWindowTitle(QApplication::translate("RegisterWidget", "Form", 0));
        label->setText(QApplication::translate("RegisterWidget", "Register", 0));
        lblRegister->setText(QApplication::translate("RegisterWidget", "0x00", 0));
        lblValue->setText(QApplication::translate("RegisterWidget", "N/A", 0));
        btnPlot->setText(QApplication::translate("RegisterWidget", "Plot", 0));
    } // retranslateUi

};

namespace Ui {
    class RegisterWidget: public Ui_RegisterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_WIDGET_H
