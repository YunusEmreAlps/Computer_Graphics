#include "nokta.h"
#include "resim.h"
#include "mainwindow.h"

nokta::nokta(QWidget *parent) :
    QLabel(parent)
{
    setScaledContents(true);
    QImage resim(":/resim/images/nokta.png");
    setPixmap(QPixmap::fromImage(resim));
}

void nokta::mousePressEvent(QMouseEvent *event)
{
    ilkKonum = event->pos();
}

void nokta::mouseReleaseEvent(QMouseEvent *event)
{
    int X = (event->x() - ilkKonum.x()) + x();
    int Y = (event->y() - ilkKonum.y()) + y();
    setGeometry(X, Y, 10,10);
    if (anafrm->hangiEgri == 0) {
        adres->cizBezier();
    } else {
        adres->cizBspline();
    }
}
