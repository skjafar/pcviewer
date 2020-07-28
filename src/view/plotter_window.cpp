#include "view/plotter_window.h"
#include "ui_plotter_window.h"

#include <QFileDialog>
#include <QTextStream>
#include <QDateTime>
#include <QFile>
#include <QDir>

#include "common.h"

PlotterWindow::PlotterWindow(RegistersMap* registers, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlotterWindow),
    m_registers(registers),
    m_paused(false)
{
    ui->setupUi(this);
    ui->plot->xAxis->setLabel("Time");
    ui->plot->setInteractions(QCP::Interaction::iRangeZoom | QCP::Interaction::iRangeDrag);
    //ui->plot->legend->setVisible(true);

    m_zeroTime = QTime::currentTime();
    graphsTimeSpan = ui->txtTimeSpan->text().toDouble();

    ui->txtPlotLower->setValidator(doubleValidator);
    ui->txtPlotUpper->setValidator(doubleValidator);
    ui->txtTimeSpan->setValidator(doubleValidator);

    connect(ui->txtPlotUpper, SIGNAL(returnPressed()), this, SLOT(manualUpdateAxis()));
    connect(ui->txtPlotLower, SIGNAL(returnPressed()), this, SLOT(manualUpdateAxis()));
    connect(ui->txtTimeSpan, SIGNAL(returnPressed()(const QString &)), this, SLOT(on_txtTimeSpan_returnPressed()));

    QMap<uint16_t, Register*>::const_iterator iterator;
    for (iterator = m_registers->registersByAddress.begin(); iterator != m_registers->registersByAddress.end(); iterator++)
    {
        ui->cmbRegisters->addItem(iterator.value()->name(), iterator.key());
    }

    ui->cmbRegisters->setCurrentText("ILOAD");
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(addGraph()));
    connect(ui->btnRemove, SIGNAL(clicked()), this, SLOT(removeGraph()));
}

void PlotterWindow::addGraph()
{
    if (ui->cmbRegisters->currentIndex() >= 0)
    {
        Register *register_ = m_registers->get(ui->cmbRegisters->itemData(ui->cmbRegisters->currentIndex()).toUInt());
        emit addGraph(register_);
    }
}

void PlotterWindow::removeGraph()
{
    QString registerName;

    if (!ui->lstPlots->selectedItems().empty())
        registerName = ui->lstPlots->selectedItems().first()->text();
    else if (ui->lstPlots->count() == 1)
        registerName = ui->lstPlots->item(0)->text();
    else
        return;

    Register *register_ = m_registers->get(registerName);
    emit removeGraph(register_);
}

void PlotterWindow::closeEvent(QCloseEvent *)
{
    this->deleteLater();
}

PlotterWindow::~PlotterWindow()
{
    delete ui;
}

void PlotterWindow::onGraphUpdated()
{
    if (m_paused) return;

    double sec = m_zeroTime.msecsTo(QTime::currentTime()) / 1000.0;

    if (ui->optAutomatic->isChecked())
        ui->plot->rescaleAxes();        
    ui->plot->xAxis->setRange(sec - graphsTimeSpan, sec);
    ui->plot->replot();
}

WaveformGraph::WaveformGraph(QCPGraph *graph, Register *register_, QTime zeroTime, int index, bool *paused, double timeSpan,QWidget *parent) :
    QObject(parent),
    m_graph(graph),
    m_register(register_),
    m_zeroTime(zeroTime),
    m_paused(paused),
    graphTimeSpan(timeSpan)
{
    graph->setName(register_->name());
    graph->setPen(QPen(getSequentialColor(index)));
    RegisterPoll* poller = m_register->getPoller(REFRESH_PERIOD, this);
    connect(m_register, SIGNAL(onReadReply()), this, SLOT(addPoint()));
    poller->enablePoll(true);
}

void WaveformGraph::addPoint()
{
    if (m_register->valid())
    {
        double sec = m_zeroTime.msecsTo(QTime::currentTime()) / 1000.0;

        if (!*m_paused)
        {
            m_graph->removeDataBefore(sec - graphTimeSpan);
        }

        m_graph->addData(sec, m_register->type() == REGISTER_TYPE_FLOATING ? m_register->floatVal() : m_register->intVal());
        emit onGraphUpdated();
    }
}

QPen WaveformGraph::pen() const
{
    return m_graph->pen();
}

void WaveformGraph::removeGraph()
{
    m_graph->clearData();
}

void WaveformGraph::setTimeSpan(double timeSpan)
{
    graphTimeSpan = timeSpan;
}

WaveformGraph::~WaveformGraph() {}

void PlotterWindow::on_optManual_toggled(bool checked)
{
    if (checked)
    {
        double max = ui->plot->yAxis->range().upper;
        double min = ui->plot->yAxis->range().lower;
        ui->txtPlotUpper->setText(QString::number(max, 'f', 3));
        ui->txtPlotLower->setText(QString::number(min, 'f', 3));

        this->manualUpdateAxis();
    }
}


void PlotterWindow::manualUpdateAxis()
{
    double upper = ui->txtPlotUpper->text().toDouble();
    double lower = ui->txtPlotLower->text().toDouble();



    ui->plot->yAxis->setRange(lower, upper);
    ui->plot->replot();

}

void PlotterWindow::addGraph(Register *register_)
{
    if (m_graphs.contains(register_)) return;

    int index = ui->plot->graphCount();
    WaveformGraph *graph = new WaveformGraph(ui->plot->addGraph(ui->plot->xAxis, ui->plot->yAxis), register_, m_zeroTime, index, &m_paused, graphsTimeSpan, this);
    connect(graph, SIGNAL(onGraphUpdated()), this, SLOT(onGraphUpdated()));

    QListWidgetItem *item = new QListWidgetItem(register_->name());
    item->setBackgroundColor(graph->pen().color());
    ui->lstPlots->addItem(item);

    m_graphs[register_] = QPair<WaveformGraph *, QListWidgetItem *>(graph, item);
    ui->plot->replot();
}

void PlotterWindow::removeGraph(Register *register_)
{
    if (!m_graphs.contains(register_)) return;

    QPair<WaveformGraph *, QListWidgetItem *> pair = m_graphs[register_];
    WaveformGraph *graph = pair.first;
    graph->removeGraph();
    delete graph;

    QListWidgetItem *item = pair.second;
    item->listWidget()->removeItemWidget(item);
    delete item;

    m_graphs.remove(register_);
    if (!m_paused) ui->plot->replot();
}
void PlotterWindow::on_btnSavePNG_clicked()
{
    QString filepath = QFileDialog::getSaveFileName(this, "Save Plot", QString(), "PNG (*.png)");
    if (filepath.isEmpty()) return;

    ui->plot->savePng(filepath, 0, 0, 2.0);
}

void PlotterWindow::on_btnSaveData_clicked()
{
    QString folder = QFileDialog::getExistingDirectory(this, "Select Folder to Save Data To");
    if (folder.isEmpty()) return;
;
    // foreach graph
    int graphIndex;
    for (graphIndex = 0; graphIndex < ui->plot->graphCount(); graphIndex++)
    {
        QCPGraph *graph = ui->plot->graph(graphIndex);

        // create file
        QString filepath = QDir(folder).filePath(graph->name() + ".dat");
        QFile file(filepath);
        if (!file.open(QIODevice::WriteOnly)) return;

        QTextStream stream(&file);
        stream << "# Data file generated on " << QDateTime::currentDateTime().toString() << endl;
        stream << "# " << graph->name() << endl;
        stream << endl;
        stream << "# Time \t Value" << endl;

        // get data points
        QCPDataMap *data = graph->data();
        QCPDataMap::const_iterator it;
        for (it = data->constBegin(); it != data->constEnd(); it++)
        {
            // write to file
            stream << QString::number(it->key) << " \t " << QString::number(it->value) << endl;
        }
    }
}

void PlotterWindow::on_btnPause_toggled(bool checked)
{
    m_paused = checked;
}

void PlotterWindow::on_txtTimeSpan_returnPressed()
{
    graphsTimeSpan = ui->txtTimeSpan->text().toDouble();
    auto lastGraph = m_graphs.cend();
    for (auto graph = m_graphs.cbegin(); graph != lastGraph; ++graph)
    {
        graph->first->setTimeSpan(graphsTimeSpan);
    }
    onGraphUpdated();
}
