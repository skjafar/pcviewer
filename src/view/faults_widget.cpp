#include "view/faults_widget.h"
#include "ui_faults_widget.h"

FaultsWidget::FaultsWidget(QString title, Register *register_, FaultsMap *faultsMap, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaultsWidget), m_register(register_), m_faultsMap(faultsMap)
{
    ui->setupUi(this);

    ui->lblTitle->setText(title);

    m_faultLabels[0] = ui->lblFault0;
    m_faultLabels[1] = ui->lblFault1;
    m_faultLabels[2] = ui->lblFault2;
    m_faultLabels[3] = ui->lblFault3;

    register_->getPoller(this)->enablePoll(true);
    connect(register_, SIGNAL(onChange()), this, SLOT(onFaultsChanged()));

    onFaultsChanged();
}

void FaultsWidget::onFaultsChanged()
{
    if (m_register->valid())
    {
        uint32_t value = m_register->intVal();

        for (int i = 0; i < 4; i++)
        {
            uint8_t fault = value & 0xFF;
            value >>= 8;

            QString faultName = m_faultsMap->get(fault);
            if (faultName.isEmpty())
                m_faultLabels[i]->setText("Unknown fault (0x" + QString::number(fault, 16) + ")");
            else
                m_faultLabels[i]->setText(faultName);
        }
    }
    else
    {
        for (int i = 0; i < 4; i++)
            m_faultLabels[i]->setText("N/A");
    }
}

FaultsWidget::~FaultsWidget()
{
    delete ui;
}

void FaultsWidget::on_btnClear_clicked()
{
    m_register->write(0x00);
}
