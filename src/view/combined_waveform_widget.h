#ifndef COMBINED_WAVEFORM_WIDGET_H
#define COMBINED_WAVEFORM_WIDGET_H

#include <QWidget>

#include "model/register.h"
#include "model/block.h"
#include "data/data.h"

namespace Ui {
class CombinedWaveformWidget;
}

class CombinedWaveformWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CombinedWaveformWidget(QString name,
                                    Register *size0Register, Register *period0Register, Register *gain0Register,  Register *delay0Trigger,
                                    Register *size1Register, Register *period1Register, Register *gain1Register,  Register *delay1Trigger,
                                    Register *size2Register, Register *period2Register, Register *gain2Register,  Register *delay2Trigger,
                                    Register *size3Register, Register *period3Register, Register *gain3Register,  Register *delay3Trigger,
#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
                            Register *commandRegister,
#endif
                            Block *waveform0Block, Block *waveform1Block, Block *waveform2Block, Block *waveform3Block, QWidget *parent = 0);
    ~CombinedWaveformWidget();

private slots:

    void plotWaveform(Block *block, QByteArray data);
    void waveformError(Block *block, request_error_t errCode);

    void on_btnPlot_clicked();

private:
    void accessingRAM(bool enable);

    int order = 0;
    float lastValue = STANDBY_CURRENT;
    float lastTime = 0;

    Ui::CombinedWaveformWidget *ui;
    QString m_name;

    Register *m_size0Register;
    Register *m_period0Register;
    Register *m_gain0Register;
    Register *m_delay0Register;

    Register *m_size1Register;
    Register *m_period1Register;
    Register *m_gain1Register;
    Register *m_delay1Register;

    Register *m_size2Register;
    Register *m_period2Register;
    Register *m_gain2Register;
    Register *m_delay2Register;

    Register *m_size3Register;
    Register *m_period3Register;
    Register *m_gain3Register;
    Register *m_delay3Register;

#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
    Register *m_commandRegister;
#endif
    Block *m_waveform0Block;
    Block *m_waveform1Block;
    Block *m_waveform2Block;
    Block *m_waveform3Block;
};


#endif // COMBINED_WAVEFORM_WIDGET_H
