#ifndef DPC_FAULTS_WINDOW_H
#define DPC_FAULTS_WINDOW_H

#include <QDialog>
#include "model/registers_map.h"

namespace Ui {
class DPC_FAULTS_WINDOW;
}

class DPC_FAULTS_WINDOW : public QDialog
{
    Q_OBJECT

public:
    explicit DPC_FAULTS_WINDOW(RegistersMap* registers, QWidget *parent = 0);
    ~DPC_FAULTS_WINDOW();


private:
    Ui::DPC_FAULTS_WINDOW *ui;
    Register *Faults_register;
    Register *Warnings_register;

private slots:
    void onDPCFaultsChanged();
    void onDPCWarningsChanged();
};

#endif // DPC_FAULTS_WINDOW_H
