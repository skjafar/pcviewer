#ifndef FAULTS_WIDGET_H
#define FAULTS_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QMap>

#include "model/register.h"
#include "model/faults_map.h"

namespace Ui {
class FaultsWidget;
}

class FaultsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FaultsWidget(QString title, Register *register_, FaultsMap *faultsMap, QWidget *parent = 0);
    ~FaultsWidget();

private slots:
    void onFaultsChanged();

    void on_btnClear_clicked();

private:
    Ui::FaultsWidget *ui;
    Register *m_register;
    QLabel *m_faultLabels[4];
    FaultsMap *m_faultsMap;
};

#endif // FAULTS_WIDGET_H
