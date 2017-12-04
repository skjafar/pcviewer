#ifndef REGISTERSWINDOW_H
#define REGISTERSWINDOW_H

#include <QMainWindow>
#include <view/register_widget.h>
#include "model/registers_map.h"

namespace Ui {
class RegistersWindow;
}

class RegistersWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegistersWindow(RegistersMap *m_registers, QWidget *parent = 0);
    ~RegistersWindow();

	void insertWidget(RegisterWidget *widget);
	void insertSplitter(QString string);

private slots:
    void addRegisterWidget();

private:
    Ui::RegistersWindow *ui;
    RegistersMap *m_registers;
};

#endif // REGISTERSWINDOW_H
