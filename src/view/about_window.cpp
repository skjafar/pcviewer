#include "about_window.h"
#include "ui_about_window.h"
#include <QDateTime>
#include "build_number.h"
#include "data/data.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);

    ui->lblVersion->setText(QString("%1.%2").arg(VERSION).arg(BUILD_NUMBER));

    QString buildDate = __DATE__;
    QStringList buildDateList = buildDate.split(" ");
    ui->lblYear->setText(buildDateList[2]);
}

AboutWindow::~AboutWindow()
{
    delete ui;
}
