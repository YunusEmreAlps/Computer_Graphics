#ifndef CANVAS_H
#define CANVAS_H

#include <QLabel>
#include <QMouseEvent>

class canvas : public QLabel
{
    Q_OBJECT
public:
    explicit canvas(QWidget *parent = nullptr);
    // Bresenham's Circle Drawing Algorithm
    void symmetry(int x, int y);
    void fillCircle(int r);
    void bresenhamDrawCircle(int r);

private:
    QRgb color;
    QImage theme;
    QPoint point;

    // Function
    void mousePressEvent(QMouseEvent *);


signals:

public slots:
};

#endif // CANVAS_H
