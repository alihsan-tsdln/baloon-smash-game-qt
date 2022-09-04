#ifndef BALOON_H
#define BALOON_H

#include "dialog.h"
#include <QLabel>
#include "ui_dialog.h"


class baloon : public QLabel
{
    Q_OBJECT

signals:
    void clicked();

public:
    baloon(QDialog *parent=0, Ui::Dialog *uiDialog = 0);
    void mousePressEvent(QMouseEvent* event);
    using QLabel :: QLabel;

private slots:
    void movement();
    void destroyed();
    void destroyer();

private:
    Ui::Dialog *ui;
    bool moves = true;
};

#endif // BALOON_H
