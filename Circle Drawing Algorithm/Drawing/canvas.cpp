#include "canvas.h"
#include <qmath.h>

canvas::canvas(QWidget *parent) : QLabel(parent)
{
    // canvas
    QImage canvasbackground(600, 600, QImage::Format_RGB32);
    setPixmap(QPixmap::fromImage(canvasbackground));

    // Variables
    theme = canvasbackground;
    color = qRgb(255, 255, 0);
}

void canvas::drawCircle(double r)
{
    double x, y;
    double angle = 0.0;
    double pointx, pointy;

    pointx = point.x();
    pointy = point.y();

    // Drawing
    while(angle < 360){
        x = pointx + (r * (cos(qDegreesToRadians(angle))));
        y = pointy + (r * (sin(qDegreesToRadians(angle))));
        angle += 0.01;

        theme.setPixel(round(x), round(y), color);
    }
    setPixmap(QPixmap::fromImage(theme));
}

void canvas::mousePressEvent(QMouseEvent *event)
{
    point = event -> pos();
    drawCircle(100.0);
}
