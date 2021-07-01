#include "resim.h"
#include "mainwindow.h"
#include <math.h>
#include <QApplication>
#include <QMessageBox>

resim::resim(QWidget *parent) :
    QLabel(parent)
{
    setFrameShape(QFrame::Box);
    deger = qRgb(255,255,255);
    QImage ortam(800,800,QImage::Format_RGB32);
    setPixmap(QPixmap::fromImage(ortam));
    res = ortam;
}

bool resim::resmiKaydet(QString nereye)
{
    return res.save(nereye);
}

void resim::cizBezier()
{
    QPoint nokta;
    double u = 0.00;
    while (u <= 1) {
        QApplication::processEvents();
        nokta = funcBezier(u, noktalar.size());
        res.setPixel(nokta.x(),nokta.y(),deger);
        setPixmap(QPixmap::fromImage(res));
        u += 0.001;
    }
}

void resim::cizBspline()
{
    QPoint nokta;
    double u = 0.0;
    while (u < dugumVektor[dugumVektor.size() - 1]) {
        QApplication::processEvents();
        nokta = spline(u,dugumK);
        res.setPixel(nokta.x(),nokta.y(),deger);
        setPixmap(QPixmap::fromImage(res));
        u += 0.001;
    }
}

void resim::mousePressEvent(QMouseEvent *event)
{
    nokta *yeninokta = new nokta(this);
    yeninokta->setGeometry(event->x(), event->y(), 10,10);
    yeninokta->adres = this;
    yeninokta->anafrm = anaform;
    noktalar.push_back(yeninokta);
    yeninokta->show();
}

int resim::faktoriyel(int a)
{
    if (a == 0) {
        return 1;
    } else {
        return a * faktoriyel(a - 1);
    }
}

QPoint resim::funcBezier(double u, int noktasayisi)
{
    QPoint yeniNokta;
    double X = 0.0, Y = 0.0;
    for (int i = 0; i < noktasayisi; ++i) {
        X += noktalar[i]->x() * Cfonksiyon(noktasayisi - 1, i) * powl(u, i) * powl(1 - u, (noktasayisi - 1) - i);
        Y += noktalar[i]->y() * Cfonksiyon(noktasayisi - 1, i) * powl(u, i) * powl(1 - u, (noktasayisi - 1) - i);
    }
    yeniNokta.setX(round(X));
    yeniNokta.setY(round(Y));
    return yeniNokta;
}

double resim::Cfonksiyon(int n, int i)
{
    return faktoriyel(n) / (faktoriyel(i) * faktoriyel( n - i));
}

//*************** Spline Fonksiyonlari asagidadir.***************//

double resim::splineFunc(int i, int k, double u)
{
    int payda;
    double v;
    if (k == 1) {
        v = 0.0;
        if ((dugumVektor[i] <= u) && (u < dugumVektor[i + 1])) {
            v = 1.0;
        }
    } else {
        v = 0.0;
        payda = dugumVektor[i + k - 1] - dugumVektor[i];
        if (payda != 0) {
            v = (u-dugumVektor[i]) * splineFunc(i, k -1, u) / payda;
        }
        payda = dugumVektor[i + k] - dugumVektor[i + 1];
        if (payda != 0) {
            v += (dugumVektor[i + k] - u) * splineFunc(i + 1, k - 1, u) / payda;
        }
    }
    return v;
}

QPoint resim::spline(double u, int k)
{
    QPoint yeniNokta;
    double X = 0.0, Y = 0.0, carpan;
    for (int i = 0; i < noktalar.size(); ++i) {
        carpan = splineFunc(i, k, u);
        X += noktalar[i]->x() * carpan;
        Y += noktalar[i]->y() * carpan;
    }
    yeniNokta.setX(X);
    yeniNokta.setY(Y);
    return yeniNokta;
}

