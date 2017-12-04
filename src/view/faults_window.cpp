#include "faults_window.h"
#include "ui_faults_window.h"

FaultsWindow::FaultsWindow(RegistersMap *registers, FaultsMap *faultsMap, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FaultsWindow)
{
    ui->setupUi(this);

    ui->gridLayout->addWidget(new FaultsWidget("Faults", registers->get(DISORDERS_REGISTER_NAME), faultsMap), 0, 0);
    ui->gridLayout->addWidget(new FaultsWidget("Startup Faults", registers->get(STARTUP_DISORDERS_REGISTER_NAME), faultsMap), 0, 1);
    ui->gridLayout->addWidget(new FaultsWidget("Runtime Faults", registers->get(RUNTIME_DISORDERS_REGISTER_NAME), faultsMap), 1, 0);
    ui->gridLayout->addWidget(new FaultsWidget("Shutdown Faults", registers->get(SHUTDOWN_DISORDERS_REGISTER_NAME), faultsMap), 1, 1);
}

FaultsWindow::~FaultsWindow()
{
    delete ui;
}
