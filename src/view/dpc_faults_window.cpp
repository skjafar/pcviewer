#include "dpc_faults_window.h"
#include "ui_dpc_faults_window.h"

DPC_FAULTS_WINDOW::DPC_FAULTS_WINDOW(RegistersMap* registers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DPC_FAULTS_WINDOW)
{
    ui->setupUi(this);
    Faults_register = registers->get(FAULTS_REGISTER_NAME);
    Faults_register->getPoller(this)->enablePoll(true);
    connect(Faults_register, SIGNAL(onChange()), this, SLOT(onDPCFaultsChanged()));

    ui->setupUi(this);
    Warnings_register = registers->get(WARNINGS_REGISTER_NAME);
    Warnings_register->getPoller(this)->enablePoll(true);
    connect(Warnings_register, SIGNAL(onChange()), this, SLOT(onDPCWarningsChanged()));
    onDPCFaultsChanged();

}

DPC_FAULTS_WINDOW::~DPC_FAULTS_WINDOW()
{
    delete ui;
}

void DPC_FAULTS_WINDOW::onDPCFaultsChanged()
{
    if (Faults_register->valid())
    {
        //Fast Faults
        if (Faults_register->uintVal() & 0x00000001)
            ui->lblPULSInterlockLED->setPixmap(QPixmap(":/resources/images/red-on.png"));
        else
            ui->lblPULSInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        if (Faults_register->uintVal() & 0x00000002)
            ui->lblDCCTInterlockLED->setPixmap(QPixmap(":/resources/images/red-on.png"));
        else
            ui->lblDCCTInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        if (Faults_register->uintVal() & 0x00000004)
            ui->lblPCOInterlockLED->setPixmap(QPixmap(":/resources/images/red-on.png"));
        else
            ui->lblPCOInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        if (Faults_register->uintVal() & 0x00000008)
            ui->lblVMONInterlockLED->setPixmap(QPixmap(":/resources/images/red-on.png"));
        else
            ui->lblVMONInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        if (Faults_register->uintVal() & 0x00000010)
            ui->lblILOADInterlockLED->setPixmap(QPixmap(":/resources/images/red-on.png"));
        else
            ui->lblILOADInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        if (Faults_register->uintVal() & 0x00000020)
            ui->lblIEARTHInterlockLED->setPixmap(QPixmap(":/resources/images/red-on.png"));
        else
            ui->lblIEARTHInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        if (Faults_register->uintVal() & 0x00000040)
            ui->lbldIdtInterlockLED->setPixmap(QPixmap(":/resources/images/red-on.png"));
        else
            ui->lbldIdtInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        if (Faults_register->uintVal() & 0x00000080)
            ui->lblMAGNETInterlockLED->setPixmap(QPixmap(":/resources/images/red-on.png"));
        else
            ui->lblMAGNETInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        if (Faults_register->uintVal() & 0x00000100)
            ui->lblESTOPInterlockLED->setPixmap(QPixmap(":/resources/images/red-on.png"));
        else
            ui->lblESTOPInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        //Slow Interlocks
        if (Faults_register->uintVal() & 0x01000000)
            ui->lblERRORInterlockLED->setPixmap(QPixmap(":/resources/images/red-on.png"));
        else
            ui->lblERRORInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        if (Faults_register->uintVal() & 0x02000000)
            ui->lblTEMPERATUREInterlockLED->setPixmap(QPixmap(":/resources/images/red-on.png"));
        else
            ui->lblTEMPERATUREInterlockLED->setPixmap(QPixmap(":/resources/images/red-off.png"));
    }
}

void DPC_FAULTS_WINDOW::onDPCWarningsChanged()
{
    if (Faults_register->valid())
    {
        //Warnings
        if (Faults_register->uintVal() & 0x00000001)
            ui->lblTTYTimeOutWarningLED->setPixmap(QPixmap(":/resources/images/red-on.png"));
        else
            ui->lblTTYTimeOutWarningLED->setPixmap(QPixmap(":/resources/images/red-off.png"));

        if (Faults_register->uintVal() & 0x00000004)
            ui->lbldIdtWarningLED->setPixmap(QPixmap(":/resources/images/red-on.png"));
        else
            ui->lbldIdtWarningLED->setPixmap(QPixmap(":/resources/images/red-off.png"));
    }
}
