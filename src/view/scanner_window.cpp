#include "view/scanner_window.h"
#include "ui_scanner_window.h"

#include <QNetworkInterface>
#include <QMessageBox>

#include "data/data.h"

ScannerWindow::ScannerWindow(DevicesMap *devicesMap, QWidget *parent) :
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

    m_devices = devicesMap;
    m_scanner = new CardScanner(this);
    connect(m_scanner, SIGNAL(onCardFound(QString, uint32_t)), this, SLOT(onCardFound(QString, uint32_t)));
    connect(m_scanner, SIGNAL(onScanDone()), this, SLOT(onScanDone()));

    if (SEARCH_AUTOMATICALLY)
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
    QString IP;
    QStringList words;

    if (ui->txtIP->text().isEmpty())
    {
        QMessageBox::warning(this, "Connect", "A Device must be specified before connecting.");
        return;
    }

    words = ui->txtIP->text().split(" ");
    IP = words.value(0);
    emit connectTo(IP);
}

void ScannerWindow::connectTo(QString IP)
{
    this->IP = IP;
    emit done(QDialog::Accepted);
}

void ScannerWindow::onCardFound(QString IP, uint32_t ID)
{
    QString deviceName = m_devices->get(ID);
    ui->lstCards->addItem(IP + " " + deviceName);
}

void ScannerWindow::onScanDone()
{
    QString IP;
    QStringList words;
    ui->btnScan->setEnabled(true);
    ui->btnScan->setText("Scan");

    if (CONNECT_AUTOMATICALLY && ui->lstCards->count() == 1)
    {
        words = ui->lstCards->item(0)->text().split(" ");
        IP = words.value(0);
        emit connectTo(IP);
    }
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
