#include <QApplication>
#include <QMessageBox>
#include <QtGlobal>
#include <QTime>

#include "view/main_window.h"
#include "view/scanner_window.h"

#include "model/blocks_map.h"
#include "model/registers_map.h"
#include "model/parameter_set.h"
#include "model/faults_map.h"
#include "model/communicator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qsrand(QTime::currentTime().msec());

    ScannerWindow scanner;
    if (scanner.exec() != QDialog::Accepted) return 0;

    Communicator communicator(scanner.IP, DEFAULT_CONTROLLER_PORT);
    //Communicator communicator("localhost", DEFAULT_CONTROLLER_PORT);
    RegistersMap registers(&communicator);
    BlocksMap blocks(&communicator, &registers);
    FaultsMap faults;
    ParameterDefinitions parameterDefinitions;

    QString registersMapFile = QApplication::applicationDirPath() + "/" + REGISTERS_FILE;
    QString blocksMapFile = QApplication::applicationDirPath() + "/" + BLOCKS_FILE;
    QString faultsMapFile = QApplication::applicationDirPath() + "/" + FAULTS_FILE;
    QString parametersMapFile = QApplication::applicationDirPath() + "/" + PARAMETERS_FILE;

    if (registers.loadFromFile(registersMapFile) && blocks.loadFromFile(blocksMapFile) && faults.loadFromFile(faultsMapFile) && parameterDefinitions.loadFromFile(parametersMapFile))
    {
        MainWindow window(&registers, &blocks, &faults, &parameterDefinitions);
        window.show();

        return app.exec();
    }
    else
    {
        // failed to load maps
        QMessageBox::critical(0, "Registers/Blocks/Faults/Parameters Map", "Failed to load registers/blocks/faults/parameters map file.\n\nLooking in:\n  " + registersMapFile + "\n  " + blocksMapFile + "\n  " + faultsMapFile + "\n  " + parametersMapFile);
        return 1;
    }
}
