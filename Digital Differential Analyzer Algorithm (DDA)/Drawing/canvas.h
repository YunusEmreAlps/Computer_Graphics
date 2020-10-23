#ifndef CANVAS_H
#define CANVAS_H

#include <QLabel>
#include <QMouseEvent>

class canvas : public QLabel
{
    Q_OBJECT
public:
    explicit canvas(QWidget *parent = nullptr);
    void drawline();

private:
    bool control;
    QRgb color;
    QPoint point1, point2;
    QImage theme;

    void mousePressEvent(QMouseEvent*);

signals:

public slots:
};

#endif // IMAGECANVAS_H
