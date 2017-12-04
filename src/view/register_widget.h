#ifndef REGISTER_WIDGET_H
#define REGISTER_WIDGET_H

#include <QWidget>

#include "model/registers_map.h"
#include "model/register.h"

#include "view/plotter_window.h"

namespace Ui {
class RegisterWidget;
}

class RegisterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RegisterWidget(RegistersMap* registers, QWidget* parent = 0);
    explicit RegisterWidget(RegistersMap* registers, Register* reg, QWidget* parent = 0);
    ~RegisterWidget();

    void changeConnectedRegister(Register*);

public slots:
    void focusRegisterChoice();

private slots:
    void onAddressChange(int);
    void onValueChange();
    void onError(request_error_t);

    void on_txtValue_returnPressed();
    void on_btnPlot_clicked();

private:
    Ui::RegisterWidget *ui;
    Register* m_register;
    RegisterPoll* m_poller;
    RegistersMap* m_registers;
};

#endif // REGISTER_WIDGET_H
