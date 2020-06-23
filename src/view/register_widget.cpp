#include "view/register_widget.h"
#include "ui_register_widget.h"

RegisterWidget::RegisterWidget(RegistersMap* registers, QWidget* parent) :
    QWidget(parent), ui(new Ui::RegisterWidget), m_register(NULL), m_poller(NULL), m_registers(registers)
{
    ui->setupUi(this);

    {
        ui->cmbRegisters->addItem("");
        ui->txtAddress->setText("");
        QMap<uint16_t, Register*>::const_iterator iterator;
        for (iterator = registers->registersByAddress.begin(); iterator != registers->registersByAddress.end(); iterator++)
        {
            ui->cmbRegisters->addItem(iterator.value()->name(), iterator.key());
        }
        connect(ui->cmbRegisters, SIGNAL(currentIndexChanged(int)), this, SLOT(onAddressChange(int)));
        connect(ui->txtAddress, SIGNAL(returnPressed()), this, SLOT(on_txtAddress_ReturnPressed()));
    }

    onAddressChange(0);
}

RegisterWidget::RegisterWidget(RegistersMap* registers, Register* reg, QWidget* parent) :
    QWidget(parent), ui(new Ui::RegisterWidget), m_register(NULL), m_poller(NULL), m_registers(registers)
{
    ui->setupUi(this);

	ui->cmbRegisters->addItem("");
	QMap<uint16_t, Register*>::const_iterator iterator;
	for (iterator = registers->registersByAddress.begin(); iterator != registers->registersByAddress.end(); iterator++)
	{
        if (iterator.value()->name() != "N/A")
        {
            ui->cmbRegisters->addItem(iterator.value()->name(), iterator.key());
        }
	}
	connect(ui->cmbRegisters, SIGNAL(currentIndexChanged(int)), this, SLOT(onAddressChange(int)));
    connect(ui->txtAddress, SIGNAL(returnPressed()), this, SLOT(on_txtAddress_ReturnPressed()));

	int index = 1;
	for (iterator = registers->registersByAddress.begin(); iterator != registers->registersByAddress.end(); iterator++)
	{
		if (iterator.value()->name() == reg->name())
			break;
		index++;
	}

	ui->cmbRegisters->setCurrentIndex(index);
    onAddressChange(index);
}

RegisterWidget::~RegisterWidget()
{
    delete ui;
}

void RegisterWidget::onValueChange()
{
    ui->lblValue->setText(m_register->toString());
}

void RegisterWidget::onError(request_error_t errorCode)
{
    ui->lblValue->setText(SomeRequest::getErrorDesc(errorCode));
}

void RegisterWidget::onAddressChange(int index)
{
    ui->lblValue->setText("N/A");

    if (index > 0)
    {
        changeConnectedRegister(m_registers->get(ui->cmbRegisters->itemData(index).toUInt()));
        ui->txtAddress->setText(QString("0x%1").arg(m_register->address(), 2, 16, QChar('0')));
    }
    else
    {
        changeConnectedRegister(NULL);
    }
}

void RegisterWidget::on_txtAddress_ReturnPressed()
{
    ui->lblValue->setText("N/A");

    uint16_t lAddress = ui->txtAddress->text().toUInt(0, 16);

    if (m_registers->registersByAddress.count(lAddress) > 0)
    {
        changeConnectedRegister(m_registers->get(lAddress));
        int index = ui->cmbRegisters->findData(lAddress);

        if (index > -1)
        {
            ui->cmbRegisters->setCurrentIndex(index);
        }
        else
        {
            ui->cmbRegisters->setCurrentIndex(0);
        }

    }
    else
    {
        changeConnectedRegister(NULL);
    }
}

void RegisterWidget::changeConnectedRegister(Register* newRegister)
{
    // disconnect and delete old objects
    Register *oldRegister = m_register;
    if (oldRegister)
    {
        disconnect(oldRegister, SIGNAL(onChange()), this, SLOT(onValueChange()));
        disconnect(oldRegister, SIGNAL(onError(request_error_t)), this, SLOT(onError(request_error_t)));
    }

    RegisterPoll *oldPoller = m_poller;
    if (oldPoller)
    {
        oldPoller->enablePoll(false);
        oldPoller->deleteLater();
    }

    // connect new objects
    if (newRegister)
    {
        m_register = newRegister;
        m_poller = newRegister->getPoller(this);
        m_poller->enablePoll(true);

        connect(newRegister, SIGNAL(onChange()), this, SLOT(onValueChange()));
        connect(newRegister, SIGNAL(onError(request_error_t)), this, SLOT(onError(request_error_t)));

        ui->txtValue->setEnabled(true);
        ui->btnPlot->setEnabled(true);
        emit onValueChange();
    }
    else
    {
        m_register = NULL;
        m_poller = NULL;

        ui->txtValue->setEnabled(false);
        ui->btnPlot->setEnabled(false);
    }
}

void RegisterWidget::focusRegisterChoice()
{
    ui->cmbRegisters->setFocus();
}

void RegisterWidget::on_btnPlot_clicked()
{
    if (m_register)
    {
        PlotterWindow* window = new PlotterWindow(m_registers, this);
        window->addGraph(m_register);
        window->show();
    }
}

void RegisterWidget::on_txtValue_returnPressed()
{
    if (m_register->type() == REGISTER_TYPE_INTEGRAL)
        m_register->write((int32_t) ui->txtValue->text().toLong(NULL, 0));
    else
        m_register->write(ui->txtValue->text().toFloat());
}
