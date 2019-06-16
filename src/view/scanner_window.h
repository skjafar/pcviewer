#ifndef SCANNER_WINDOW_H
#define SCANNER_WINDOW_H

#include <QDialog>
#include <QString>
#include "model/devices_map.h"
#include "model/card_scanner.h"

namespace Ui {
class ScannerWindow;
}

class ScannerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ScannerWindow(DevicesMap *devicesMap, QWidget *parent = 0);
    ~ScannerWindow();
    QString IP;

private slots:
    void onCardFound(QString IP, uint32_t ID);
    void onScanDone();
    void connectTo(QString IP);

    void on_cmbInterfaces_currentIndexChanged(int index);
    void on_btnConnect_clicked();
    void on_btnScan_clicked();
    void on_lstCards_itemSelectionChanged();
    void on_txtIP_textChanged(const QString &arg1);

private:
    Ui::ScannerWindow *ui;
    CardScanner *m_scanner;
    DevicesMap *m_devices;
};

#endif // SCANNER_WINDOW_H
