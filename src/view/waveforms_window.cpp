#include "waveforms_window.h"
#include "ui_waveforms_window.h"

#include "data/data.h"

WaveformsWindow::WaveformsWindow(RegistersMap *registers, BlocksMap *blocks, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WaveformsWindow)
{
    ui->setupUi(this);

    ui->tabWidget->clear();

    ui->tabWidget->addTab(new WaveformWidget(
        "Waveform 0",
        registers->get(WAVEFORM_0_SIZE_REGISTER_NAME),
        registers->get(WAVEFORM_0_PERIOD_REGISTER_NAME),
        registers->get(WAVEFORM_0_FINAL_REGISTER_NAME),
        registers->get(WAVEFORM_0_TOP_REGISTER_NAME),
#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
        registers->get(COMMAND_REGISTER_NAME),
#endif
        blocks->get(WAVEFORM_0_BLOCK_NAME),
        this
    ), "Waveform 0");

    ui->tabWidget->addTab(new WaveformWidget(
        "Waveform 1",
        registers->get(WAVEFORM_1_SIZE_REGISTER_NAME),
        registers->get(WAVEFORM_1_PERIOD_REGISTER_NAME),
        registers->get(WAVEFORM_1_FINAL_REGISTER_NAME),
        registers->get(WAVEFORM_1_TOP_REGISTER_NAME),
#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
        registers->get(COMMAND_REGISTER_NAME),
#endif
        blocks->get(WAVEFORM_1_BLOCK_NAME),
        this
    ), "Waveform 1");

    ui->tabWidget->addTab(new WaveformWidget(
        "Waveform 2",
        registers->get(WAVEFORM_2_SIZE_REGISTER_NAME),
        registers->get(WAVEFORM_2_PERIOD_REGISTER_NAME),
        registers->get(WAVEFORM_2_FINAL_REGISTER_NAME),
        registers->get(WAVEFORM_2_TOP_REGISTER_NAME),
#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
        registers->get(COMMAND_REGISTER_NAME),
#endif
        blocks->get(WAVEFORM_2_BLOCK_NAME),
        this
    ), "Waveform 2");

    ui->tabWidget->addTab(new WaveformWidget(
        "Waveform 3",
        registers->get(WAVEFORM_3_SIZE_REGISTER_NAME),
        registers->get(WAVEFORM_3_PERIOD_REGISTER_NAME),
        registers->get(WAVEFORM_3_FINAL_REGISTER_NAME),
        registers->get(WAVEFORM_3_TOP_REGISTER_NAME),
#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
        registers->get(COMMAND_REGISTER_NAME),
#endif
        blocks->get(WAVEFORM_3_BLOCK_NAME),
        this
    ), "Waveform 3");

    ui->tabWidget->addTab(new CombinedWaveformWidget(
        "Combined",
        registers->get(WAVEFORM_0_SIZE_REGISTER_NAME),
        registers->get(WAVEFORM_0_PERIOD_REGISTER_NAME),
        registers->get(WAVEFORM_0_FINAL_REGISTER_NAME),
        registers->get(WAVEFORM_0_TOP_REGISTER_NAME),
        registers->get(WAVEFORM_1_SIZE_REGISTER_NAME),
        registers->get(WAVEFORM_1_PERIOD_REGISTER_NAME),
        registers->get(WAVEFORM_1_FINAL_REGISTER_NAME),
        registers->get(WAVEFORM_1_TOP_REGISTER_NAME),
        registers->get(WAVEFORM_2_SIZE_REGISTER_NAME),
        registers->get(WAVEFORM_2_PERIOD_REGISTER_NAME),
        registers->get(WAVEFORM_2_FINAL_REGISTER_NAME),
        registers->get(WAVEFORM_2_TOP_REGISTER_NAME),
        registers->get(WAVEFORM_3_SIZE_REGISTER_NAME),
        registers->get(WAVEFORM_3_PERIOD_REGISTER_NAME),
        registers->get(WAVEFORM_3_FINAL_REGISTER_NAME),
        registers->get(WAVEFORM_3_TOP_REGISTER_NAME),
#ifdef ENABLE_MULTI_ACCESS_RAM_WORKAROUND
        registers->get(COMMAND_REGISTER_NAME),
#endif
        blocks->get(WAVEFORM_0_BLOCK_NAME), blocks->get(WAVEFORM_1_BLOCK_NAME), blocks->get(WAVEFORM_2_BLOCK_NAME), blocks->get(WAVEFORM_3_BLOCK_NAME),
        this
    ), "Combined");
}

WaveformsWindow::~WaveformsWindow()
{
    delete ui;
}
