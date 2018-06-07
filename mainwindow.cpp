#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QTime>
#include<QEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTime t;


   t= QTime::currentTime();

   qsrand(t.msec()+t.second()*1000);

    ui->setupUi(this);
    ui->label->setFont(QFont("小姐姐 你喜欢我吗？" , 14 ,  QFont::Bold));
    ui->pushButton->setFont(QFont("不喜欢" , 14 ,  QFont::Bold));
     ui->pushButton_2->setFont(QFont("喜欢" , 14 ,  QFont::Bold));
    ui->pushButton->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::eventFilter(QObject *target, QEvent *e)

{

        if(target == ui->pushButton)
        {
            if(e->type() == QEvent::Enter)
            {
               //QMessageBox::about(this,"x","x");
                ui->pushButton->move((qrand()% ui->centralWidget->width())
                                     ,qrand()% ui->centralWidget->height());
            }
            //
        }

        return QMainWindow::eventFilter(target, e);
}
void MainWindow::on_pushButton_2_clicked()
{
      QMessageBox::information(this,"","成功获得男票的爱",QMessageBox::Ok);
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"","再选一次",QMessageBox::Ok);
}

void MainWindow::on_pushButton_customContextMenuRequested(const QPoint &pos)
{
     QMessageBox::information(this,"","再选一次",QMessageBox::Ok);
}
