#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canvas.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_radiusValueLineEdit_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    canvas *img;
};

#endif // MAINWINDOW_H
