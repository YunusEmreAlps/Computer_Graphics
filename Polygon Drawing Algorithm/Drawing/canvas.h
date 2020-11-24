#ifndef CANVAS_H
#define CANVAS_H

#include <QLabel>
#include <QMouseEvent>

class canvas : public QLabel
{
    Q_OBJECT
public:
    explicit canvas(QWidget *parent = nullptr);
    void drawLine(QPoint point1, QPoint point2);
    void drawPolygon();

private:
    QRgb color;
    QImage theme;
    QPoint point;
    QList<QPoint> points;

    // Function
    void mousePressEvent(QMouseEvent *);
signals:

public slots:
};

#endif // CANVAS_H
