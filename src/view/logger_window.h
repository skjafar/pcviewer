#ifndef LOGGER_WINDOW_H
#define LOGGER_WINDOW_H

#include <QMainWindow>
#include <QVector>

#include "model/blocks_map.h"
#include "model/registers_map.h"

namespace Ui {
class LoggerWindow;
}

class LoggerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoggerWindow(RegistersMap *registers, QWidget *parent = 0);
    ~LoggerWindow();

    void addLogger(Block *block, QString name);

private slots:
    void onIndexRead();
    void onDataRead(Block*, QByteArray);
    void loggerStatusChanged();

    void on_btnDump_clicked();
    void on_btnStart_clicked();
    void on_btnStop_clicked();

private:
    void updateGraph();

    Ui::LoggerWindow *ui;
    QVector<Block *> m_loggers;
    QVector<QByteArray> m_data;
    QVector<QString> m_names;
    Register *m_loggerStatusRegister;
    Register *m_logIndexRegister;
    Register *m_commandRegister;
    int32_t m_index;
};

#endif // LOGGER_WINDOW_H
