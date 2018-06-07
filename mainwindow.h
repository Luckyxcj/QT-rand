#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include<QEvent>
#include<QButtonGroup>

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_customContextMenuRequested(const QPoint &pos);
    bool eventFilter(QObject *target, QEvent *e);
private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
