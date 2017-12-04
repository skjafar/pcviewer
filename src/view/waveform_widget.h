#ifndef WAVEFORM_WIDGET_H
#define WAVEFORM_WIDGET_H

#include <QWidget>

#include "model/register.h"
#include "model/block.h"

namespace Ui {
class WaveformWidget;
}

class WaveformWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WaveformWidget(QString name, Register *sizeRegister, Register *periodRegister, Register *gainRegister,  Register *delayTrigger,
#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
                            Register *commandRegister,
#endif
                            Block *waveformBlock, QWidget *parent = 0);
    ~WaveformWidget();

private slots:
    void onSizeChange();
    void onPeriodChange();
    void onGainChange();
    void onDelayChange();

    void changeSize();
    void changePeriod();
    void changeGain();
    void changeDelay();

    void plotWaveform(Block *block, QByteArray data);
    void saveWaveform(Block *block, QByteArray data);
    void waveformUploaded(Block *block);
    void waveformError(Block *block, request_error_t errCode);

    void on_btnPlot_clicked();
    void on_btnSave_clicked();
    void on_btnUpload_clicked();

private:
    void accessingRAM(bool enable);

    Ui::WaveformWidget *ui;
    QString m_name;
    Register *m_sizeRegister;
    Register *m_periodRegister;
    Register *m_gainRegister;
    Register *m_delayRegister;
#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
    Register *m_commandRegister;
#endif
    Block *m_waveformBlock;
};


#endif // WAVEFORM_WIDGET_H
