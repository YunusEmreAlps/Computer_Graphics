#ifndef NOKTA_H
#define NOKTA_H

#include <QLabel>
#include <QMouseEvent>

class resim;
class MainWindow;

class nokta : public QLabel
{
    Q_OBJECT
public:
    explicit nokta(QWidget *parent = 0);
    resim *adres;
    MainWindow *anafrm;

signals:

private:
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);

    QPoint ilkKonum;

public slots:

};

#endif // NOKTA_H
