#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::createBaloon()
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timers()));
    timer->start(1000);
}

void Dialog::init()
{
    QPalette palette;
    palette.setColor(ui->sure_lbl->foregroundRole(), Qt::blue);
    ui->sure_lbl->setPalette(palette);
    palette.setColor(ui->vurulan_lbl->foregroundRole(), Qt::green);
    ui->vurulan_lbl->setPalette(palette);
    palette.setColor(ui->kacan_lbl->foregroundRole(), Qt::red);
    ui->kacan_lbl->setPalette(palette);
    createBaloon();
}

void Dialog::timers()
{
    ui->sure_lbl->setText(QString::number(timer_count++));
    baloon *balon = new baloon(this, ui);
}
