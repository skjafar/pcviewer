#ifndef FAULTS_WINDOW_H
#define FAULTS_WINDOW_H

#include <QMainWindow>

#include "model/faults_map.h"
#include "model/registers_map.h"
#include "model/register.h"

#include "view/faults_widget.h"

namespace Ui {
class FaultsWindow;
}

class FaultsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FaultsWindow(RegistersMap *registers, FaultsMap *faultsMap, QWidget *parent = 0);
    ~FaultsWindow();

private:
    Ui::FaultsWindow *ui;
};

#endif // FAULTS_WINDOW_H
