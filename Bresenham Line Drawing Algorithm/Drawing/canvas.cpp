#include "canvas.h"
#include <math.h>

// 17010011005
// Yunus Emre Alpu

canvas::canvas(QWidget *parent) : QLabel(parent)
{
    // canvas
    QImage canvasbackground(600, 600, QImage::Format_RGB32);
    setPixmap(QPixmap::fromImage(canvasbackground));

    // variables
    control = false;
    theme = canvasbackground;
    color = qRgb(255, 255, 0); // yellow
}

int canvas::getSign(int result)
{
    if(result < 0)
        return -1;
    else if (result == 0)
        return 0;
    else
        return +1;
}

void canvas::drawLine()
{
    int i; // Loop variable
    int temp1; // Swapping
    int step = false;
    int pitch, slope; // Decision
    int point1x, point1y, point2x, point2y;

    // Point 1
    point1x = point1.x();
    point1y = point1.y();

    // Point 2
    point2x = point2.x();
    point2y = point2.y();

    // Double click
    if((point1x == point2x) && (point1y == point2y)) {
        theme.setPixel(point1x, point1y, color);
    }
    else {
        // Difference between two points
        // m = (y2 - y1) / (x2 - x1)
        int dx, dy;

        dx = abs(point2x - point1x);
        dy = abs(point2y - point1y);

        if(dy > dx){
            temp1 = dx;
            dx = dy;
            dy = temp1;
            step = true;
        }

        int sx = getSign(point2x - point1x);
        int sy = getSign(point2y - point1y);

        int x = point1x;
        int y = point1y;

        // Error
        pitch = (2 * dy) - dx;

        // -1 < m (slope) < 1
        for(i=0; i<dx; i++){

            if(pitch > 0){
                if(step == true){
                    x += sx;
                }
                else {
                    y += sy;
                }
                pitch = pitch - (2 * dx);
            }

            if(step) {
                y += sy;
            }
            else {
                x += sx;
            }

            pitch =  pitch + (2 * dy);
            theme.setPixel(x, y, color);
        }
    }

    // Update canvas state
    setPixmap(QPixmap::fromImage(theme));
}

void canvas::mousePressEvent(QMouseEvent *event)
{
    // Point 1 (Starting point)
    if(control == false){
        point1 = event->pos();
        control = true;
    }
    // Point 2 (Ending point)
    else{
        point2 = event->pos();
        control = false;
        drawLine();
    }
}
