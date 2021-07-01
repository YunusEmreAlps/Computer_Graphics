#ifndef RESIM_H
#define RESIM_H

#include <QLabel>
#include <QMouseEvent>
#include <QImage>
#include <QLineEdit>
#include "nokta.h"

class MainWindow;

class resim : public QLabel
{
    Q_OBJECT
public:
    explicit resim(QWidget *parent = 0);    
    MainWindow *anaform;
    bool resmiKaydet(QString);
    void cizBezier();
    void cizBspline();
    QList<double> dugumVektor;
    int dugumK;


signals:

public slots:
    void mousePressEvent(QMouseEvent*);

private slots:


private:
    QPoint Nokta;
    QList<nokta*> noktalar;
    QList<QLineEdit*> agirliklar;
    QRgb deger;
    QImage res;
    int faktoriyel(int);
    QPoint funcBezier(double, int);
    double Cfonksiyon(int, int);
    int dugumV(int);
    double splineFunc(int,int,double);
    QPoint spline(double, int);

};

#endif // RESIM_H
