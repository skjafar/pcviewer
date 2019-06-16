#ifndef PLOTTER_WINDOW_H
#define PLOTTER_WINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QTime>
#include <QMap>
#include <QPair>

#include "model/registers_map.h"
#include "model/register_poll.h"
#include "view/qcustomplot.h"

#define DURATION_S 200
#define REFRESH_PERIOD 10

namespace Ui {
class PlotterWindow;
}

class WaveformGraph : public QObject
{
    Q_OBJECT

public:
    explicit WaveformGraph(QCPGraph *graph, Register *register_, QTime zeroTime, int index, bool *paused, double xTime, QWidget *parent = nullptr);
    ~WaveformGraph();

    QPen pen() const;
    void removeGraph();

    void setTimeSpan(double timeSpan);

signals:
    void onGraphUpdated();

private slots:
    void addPoint();

private:
    QCPGraph *m_graph;
    Register *m_register;
    QTime m_zeroTime;
    bool *m_paused;
    double displayTime;
    double graphTimeSpan;

};

class PlotterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlotterWindow(RegistersMap* registers, QWidget *parent = nullptr);
    ~PlotterWindow();

    void closeEvent(QCloseEvent *);
    double graphsTimeSpan;

public slots:
    void addGraph(Register* register_);
    void removeGraph(Register* register_);

private slots:
    void addGraph();
    void removeGraph();

    void manualUpdateAxis();
    void onGraphUpdated();

    void on_optManual_toggled(bool checked);
    void on_btnPause_toggled(bool checked);
    void on_btnSaveData_clicked();
    void on_btnSavePNG_clicked();
    void on_txtTimeSpan_returnPressed();

private:
    Ui::PlotterWindow *ui;
    RegistersMap *m_registers;
    QMap<Register *, QPair<WaveformGraph *, QListWidgetItem *> > m_graphs;
    QTime m_zeroTime;
    QDoubleValidator *doubleValidator = new QDoubleValidator(this);
    bool m_paused;
};

#endif // PLOTTER_WINDOW_H
