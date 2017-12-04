/********************************************************************************
** Form generated from reading UI file 'block_read_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCK_READ_WINDOW_H
#define UI_BLOCK_READ_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlockReadWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnRead;
    QComboBox *cmbBlocks;
    QLineEdit *txtFile;
    QPushButton *btnWrite;
    QPushButton *btnBrowse;

    void setupUi(QMainWindow *BlockReadWindow)
    {
        if (BlockReadWindow->objectName().isEmpty())
            BlockReadWindow->setObjectName(QString::fromUtf8("BlockReadWindow"));
        BlockReadWindow->resize(284, 73);
        centralwidget = new QWidget(BlockReadWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btnRead = new QPushButton(centralwidget);
        btnRead->setObjectName(QString::fromUtf8("btnRead"));
        btnRead->setGeometry(QRect(190, 10, 85, 27));
        cmbBlocks = new QComboBox(centralwidget);
        cmbBlocks->setObjectName(QString::fromUtf8("cmbBlocks"));
        cmbBlocks->setGeometry(QRect(10, 10, 181, 26));
        txtFile = new QLineEdit(centralwidget);
        txtFile->setObjectName(QString::fromUtf8("txtFile"));
        txtFile->setEnabled(false);
        txtFile->setGeometry(QRect(10, 40, 141, 26));
        btnWrite = new QPushButton(centralwidget);
        btnWrite->setObjectName(QString::fromUtf8("btnWrite"));
        btnWrite->setGeometry(QRect(190, 40, 85, 27));
        btnBrowse = new QPushButton(centralwidget);
        btnBrowse->setObjectName(QString::fromUtf8("btnBrowse"));
        btnBrowse->setGeometry(QRect(154, 40, 31, 27));
        BlockReadWindow->setCentralWidget(centralwidget);

        retranslateUi(BlockReadWindow);

        QMetaObject::connectSlotsByName(BlockReadWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BlockReadWindow)
    {
        BlockReadWindow->setWindowTitle(QApplication::translate("BlockReadWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        btnRead->setText(QApplication::translate("BlockReadWindow", "Read", 0, QApplication::UnicodeUTF8));
        btnWrite->setText(QApplication::translate("BlockReadWindow", "Write", 0, QApplication::UnicodeUTF8));
        btnBrowse->setText(QApplication::translate("BlockReadWindow", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BlockReadWindow: public Ui_BlockReadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCK_READ_WINDOW_H
