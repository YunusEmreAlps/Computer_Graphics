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

void canvas::bresenhamDrawCircle(int r)
{
    int x = r, y = 0, pitch = 0;
    int step1, step2;
    symmetry(x, y);

    while(x > y) {
        symmetry(x, y);
        step1 = pitch + (2 * y + 1);
        step2 = pitch + ((2 * y + 1) - (2 * x + 1));
        if(abs(step1) < abs(step2)) {
            x = x;
            y = y + 1;

            pitch = step1;
        }
        else {
            x = x - 1;
            y = y + 1;
            pitch = step2;
        }
        theme.setPixel(x, y, color);
    }
    fillCircle(r);
    setPixmap(QPixmap::fromImage(theme));
}

void canvas::symmetry(int x, int y)
{
    theme.setPixel(point.x() + x, point.y() + y, color);
    theme.setPixel(point.x() + x, point.y() - y, color);
    theme.setPixel(point.x() - x, point.y() + y, color);
    theme.setPixel(point.x() - x, point.y() - y, color);
    theme.setPixel(point.x() + y, point.y() + x, color);
    theme.setPixel(point.x() + y, point.y() - x, color);
    theme.setPixel(point.x() - y, point.y() + x, color);
    theme.setPixel(point.x() - y, point.y() - x, color);
}

void canvas::fillCircle(int r)
{
    int xcor, ycor;

    for (int xcor = -r; xcor <= r; xcor++) {

        int height = (int)sqrt(r * r - xcor * xcor);
        for ( ycor = -height; ycor < height; ycor++) {
            theme.setPixel(point.x() + xcor, point.y() + ycor, color);
        }
    }
}



void canvas::mousePressEvent(QMouseEvent *event)
{
    point = event -> pos();
    bresenhamDrawCircle(100);
}
