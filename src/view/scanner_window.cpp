#include "view/scanner_window.h"
#include "ui_scanner_window.h"

#include <QNetworkInterface>
#include <QMessageBox>

#include "data/data.h"

ScannerWindow::ScannerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScannerWindow)
{
    ui->setupUi(this);

    // list all interfaces and add them to combo box
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    foreach (QNetworkInterface interface, interfaces)
    {
        if ((interface.flags() & (QNetworkInterface::CanBroadcast | QNetworkInterface::IsLoopBack)) == QNetworkInterface::CanBroadcast)
        {
            ui->cmbInterfaces->addItem(interface.humanReadableName(), interface.index());
        }
    }

    m_scanner = new CardScanner(this);
    connect(m_scanner, SIGNAL(onCardFound(QString)), this, SLOT(onCardFound(QString)));
    connect(m_scanner, SIGNAL(onScanDone()), this, SLOT(onScanDone()));

    if (CONNECT_AUTOMATICALLY)
    {
        QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
        foreach (QNetworkInterface interface, interfaces)
        {
            m_scanner->scan(interface);
        }
    }
}

ScannerWindow::~ScannerWindow()
{
    delete ui;
}

void ScannerWindow::on_cmbInterfaces_currentIndexChanged(int index)
{
    ui->btnScan->setEnabled(!ui->cmbInterfaces->itemText(index).isEmpty());
    ui->lstCards->clear();
}

void ScannerWindow::on_btnConnect_clicked()
{
    if (ui->txtIP->text().isEmpty())
    {
        QMessageBox::warning(this, "Connect", "An IP must be specified before connecting.");
        return;
    }

    emit connectTo(ui->txtIP->text());
}

void ScannerWindow::connectTo(QString IP)
{
    this->IP = IP;
    emit done(QDialog::Accepted);
}

void ScannerWindow::onCardFound(QString IP)
{
    ui->lstCards->addItem(IP);
}

void ScannerWindow::onScanDone()
{
    ui->btnScan->setEnabled(true);
    ui->btnScan->setText("Scan");

    if (CONNECT_AUTOMATICALLY && ui->lstCards->count() == 1)
        emit connectTo(ui->lstCards->item(0)->text());
}

void ScannerWindow::on_btnScan_clicked()
{
    ui->btnScan->setEnabled(false);
    ui->btnScan->setText("Scanning...");

    QNetworkInterface interface = QNetworkInterface::interfaceFromIndex(ui->cmbInterfaces->itemData(ui->cmbInterfaces->currentIndex()).toInt());
    m_scanner->scan(interface);
}

void ScannerWindow::on_lstCards_itemSelectionChanged()
{
    ui->txtIP->setText(ui->lstCards->selectedItems().front()->text());
}

void ScannerWindow::on_txtIP_textChanged(const QString &text)
{
    ui->btnConnect->setEnabled(!text.isEmpty());
}
