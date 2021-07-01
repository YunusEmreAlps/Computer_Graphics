#ifndef CANVAS_H
#define CANVAS_H

#include <QLabel>
#include <QMouseEvent>

class canvas : public QLabel
{
    Q_OBJECT
public:
    explicit canvas(QWidget *parent = nullptr);
    // Circle Drawing Algorithm
    void drawCircle(double r);
    void drawQuizCircle(double xcor, double ycor, double r);

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
