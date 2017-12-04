#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QGridLayout>
#include "view/registers_window.h"
#include "view/register_widget.h"
#include "ui_registers_window.h"

RegistersWindow::RegistersWindow(RegistersMap *registers, QWidget *parent) :
    QMainWindow(parent), ui(new Ui::RegistersWindow), m_registers(registers)
{
    ui->setupUi(this);
    connect(ui->btnAddRegisters, SIGNAL(clicked()), this, SLOT(addRegisterWidget()));

    this->setWindowTitle("DPC_CC_ID " + QString::number(registers->get("DPC_CC_ID")->uintVal()));
}

RegistersWindow::~RegistersWindow()
{
    delete ui;
}

void RegistersWindow::addRegisterWidget()
{
    RegisterWidget* widget = new RegisterWidget(m_registers, this);
    ui->lytRegisters->insertWidget(ui->lytRegisters->count() - 1, widget);
    widget->focusRegisterChoice();
}

void RegistersWindow::insertWidget(RegisterWidget *widget)
{
    ui->lytRegisters->insertWidget(ui->lytRegisters->count() - 1, widget);
}

void RegistersWindow::insertSplitter(QString title)
{
	QWidget		*widget;
	QLabel 		*label;
	QFrame 		*frame;
	QGridLayout *layout;

	layout	=	new QGridLayout;

	frame 	= 	new QFrame();
	frame->setFrameShape(QFrame::HLine);
	layout->addWidget(frame,0,0,1,3);

	label	=	new QLabel(title);
	label->setAlignment(Qt::AlignCenter);
	layout->addWidget(label,0,3,1,1);

	frame 	= 	new QFrame();
	frame->setFrameShape(QFrame::HLine);
	layout->addWidget(frame,0,4,1,3);

	widget	=	new QWidget();
	widget->setLayout(layout);

	ui->lytRegisters->insertWidget(ui->lytRegisters->count() - 1, widget);
}
