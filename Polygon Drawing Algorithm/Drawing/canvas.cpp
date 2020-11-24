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

void canvas::drawLine(QPoint point1, QPoint point2)
{
    double point1x, point1y, point2x, point2y;
    double dy, dx, x, y;

    // Point 1
    point1x = point1.x();
    point1y = point1.y();

    // Point 2
    point2x = point2.x();
    point2y = point2.y();

    dx = point2x - point1x;
    dy = point2y - point1y;

    // Number of pixel
    double step;

    if(fabs(dx) >= fabs(dy)) {
        step = fabs(dx);
    }
    else {
        step = fabs(dy);
    }

    dx = dx / step;
    dy = dy / step;

    // Drawing
    int i=0;
    x = point1x;
    y = point1y;

    for(i=0; i<step; i++) {
        x = x + dx;
        y = y + dy;
        theme.setPixel(round(x), round(y), color);
    }

    // Update
    setPixmap(QPixmap::fromImage(theme));
}

void canvas::drawPolygon()
{
    points.push_back(points[0]);
    for (int i = 0; i < (points.size() - 1); ++i) {
        drawLine(points[i], points[i+1]);
    }
    points.clear();
}

void canvas::mousePressEvent(QMouseEvent *event)
{
    points.push_back(event->pos());
}
