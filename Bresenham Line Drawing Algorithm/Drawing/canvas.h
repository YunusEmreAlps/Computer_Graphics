#ifndef CANVAS_H
#define CANVAS_H

#include <QLabel>
#include <QMouseEvent>

class canvas : public QLabel
{
    Q_OBJECT
public:
    explicit canvas(QWidget *parent = nullptr);
    // Bresenham's Drawing Line Algorithm
    void drawLine();
    int getSign(int result);

private:
    bool control;
    QRgb color;
    QImage theme;
    QPoint point1, point2;

    // Function
    void mousePressEvent(QMouseEvent *);

signals:

public slots:
};

#endif // CANVAS_H
