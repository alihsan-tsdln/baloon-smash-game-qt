#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QLabel>
#include "baloon.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QLabel *baloons[20];
    int baloon_count;
    void createBaloon();
    void init();
    int timer_count = 0;

private slots:
    void timers();
};
#endif // DIALOG_H
