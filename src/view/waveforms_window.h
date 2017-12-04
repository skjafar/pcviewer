#ifndef WAVEFORMS_WINDOW_H
#define WAVEFORMS_WINDOW_H

#include <QMainWindow>

#include "model/registers_map.h"
#include "model/blocks_map.h"

#include "view/waveform_widget.h"
#include "view/combined_waveform_widget.h"

namespace Ui {
class WaveformsWindow;
}

class WaveformsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WaveformsWindow(RegistersMap *registers, BlocksMap *blocks, QWidget *parent = 0);
    ~WaveformsWindow();

private:
    Ui::WaveformsWindow *ui;
};

#endif // WAVEFORMS_WINDOW_H
