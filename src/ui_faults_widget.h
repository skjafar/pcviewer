/********************************************************************************
** Form generated from reading UI file 'faults_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAULTS_WIDGET_H
#define UI_FAULTS_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaultsWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *lblCurrentFault;
    QLabel *lblOlderFault;
    QLabel *lblTitle;
    QPushButton *btnClear;
    QLabel *lblFault2;
    QLabel *lblFault1;
    QLabel *lblFault0;
    QLabel *lblFault3;

    void setupUi(QWidget *FaultsWidget)
    {
        if (FaultsWidget->objectName().isEmpty())
            FaultsWidget->setObjectName(QStringLiteral("FaultsWidget"));
        FaultsWidget->resize(289, 130);
        gridLayout = new QGridLayout(FaultsWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lblCurrentFault = new QLabel(FaultsWidget);
        lblCurrentFault->setObjectName(QStringLiteral("lblCurrentFault"));
        QFont font;
        font.setPointSize(10);
        lblCurrentFault->setFont(font);

        gridLayout->addWidget(lblCurrentFault, 3, 0, 1, 1);

        lblOlderFault = new QLabel(FaultsWidget);
        lblOlderFault->setObjectName(QStringLiteral("lblOlderFault"));
        QFont font1;
        font1.setPointSize(9);
        lblOlderFault->setFont(font1);

        gridLayout->addWidget(lblOlderFault, 4, 0, 1, 1);

        lblTitle = new QLabel(FaultsWidget);
        lblTitle->setObjectName(QStringLiteral("lblTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblTitle->sizePolicy().hasHeightForWidth());
        lblTitle->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        lblTitle->setFont(font2);
        lblTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lblTitle, 0, 0, 1, 2);

        btnClear = new QPushButton(FaultsWidget);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClear->setIcon(icon);
        btnClear->setIconSize(QSize(24, 17));

        gridLayout->addWidget(btnClear, 0, 2, 1, 1);

        lblFault2 = new QLabel(FaultsWidget);
        lblFault2->setObjectName(QStringLiteral("lblFault2"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblFault2->sizePolicy().hasHeightForWidth());
        lblFault2->setSizePolicy(sizePolicy1);
        lblFault2->setFont(font1);

        gridLayout->addWidget(lblFault2, 5, 1, 1, 2);

        lblFault1 = new QLabel(FaultsWidget);
        lblFault1->setObjectName(QStringLiteral("lblFault1"));
        sizePolicy1.setHeightForWidth(lblFault1->sizePolicy().hasHeightForWidth());
        lblFault1->setSizePolicy(sizePolicy1);
        lblFault1->setFont(font1);

        gridLayout->addWidget(lblFault1, 4, 1, 1, 2);

        lblFault0 = new QLabel(FaultsWidget);
        lblFault0->setObjectName(QStringLiteral("lblFault0"));
        sizePolicy1.setHeightForWidth(lblFault0->sizePolicy().hasHeightForWidth());
        lblFault0->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setPointSize(10);
        font3.setUnderline(false);
        lblFault0->setFont(font3);

        gridLayout->addWidget(lblFault0, 3, 1, 1, 2);

        lblFault3 = new QLabel(FaultsWidget);
        lblFault3->setObjectName(QStringLiteral("lblFault3"));
        sizePolicy1.setHeightForWidth(lblFault3->sizePolicy().hasHeightForWidth());
        lblFault3->setSizePolicy(sizePolicy1);
        lblFault3->setFont(font1);

        gridLayout->addWidget(lblFault3, 6, 1, 1, 2);


        retranslateUi(FaultsWidget);

        QMetaObject::connectSlotsByName(FaultsWidget);
    } // setupUi

    void retranslateUi(QWidget *FaultsWidget)
    {
        FaultsWidget->setWindowTitle(QApplication::translate("FaultsWidget", "Form", 0));
        lblCurrentFault->setText(QApplication::translate("FaultsWidget", "Current fault:", 0));
        lblOlderFault->setText(QApplication::translate("FaultsWidget", "Older faults:", 0));
        lblTitle->setText(QApplication::translate("FaultsWidget", "Startup Faults", 0));
        btnClear->setText(QApplication::translate("FaultsWidget", "  Clear", 0));
        lblFault2->setText(QApplication::translate("FaultsWidget", "No fault", 0));
        lblFault1->setText(QApplication::translate("FaultsWidget", "No fault", 0));
        lblFault0->setText(QApplication::translate("FaultsWidget", "No fault", 0));
        lblFault3->setText(QApplication::translate("FaultsWidget", "No fault", 0));
    } // retranslateUi

};

namespace Ui {
    class FaultsWidget: public Ui_FaultsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAULTS_WIDGET_H
