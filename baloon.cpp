#include "baloon.h"
#include "dialog.h"
#include <QEventLoop>

baloon::baloon(QDialog *parent, Ui::Dialog *uiDialog) : QLabel(parent)
{
    int random = rand() % 741;
    ui = uiDialog;
    setGeometry(random,100,60,60);
    random = rand() % 7;
    QPixmap pixmap(":/images/images/" + QString::number(random) + ".jpg");
    setScaledContents(true);
    setPixmap(pixmap);
    show();
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &baloon::movement);
    timer->start(10);
    connect(this, &baloon::clicked, this, &baloon::destroyed);
}

void baloon::movement()
{
    if(moves)
    {
        setGeometry(x(), y() + 1, height(), width());
        if(y() >= 600)
        {
            deleteLater();
            QString kacan_count = QString::number(ui->kacan_lbl->text().toInt() + 1);
            ui->kacan_lbl->setText(kacan_count);
        }
    }
}

void baloon::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}

void baloon::destroyed()
{
    moves = false;
    QPixmap pixmap(":/images/images/patlama.jpg");
    setPixmap(pixmap);
    setScaledContents(true);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &baloon::destroyer);
    QString vurulan_count = QString::number(ui->vurulan_lbl->text().toInt() + 1);
    ui->vurulan_lbl->setText(vurulan_count);
    timer->start(1000);
}

void baloon::destroyer()
{
    deleteLater();
}


