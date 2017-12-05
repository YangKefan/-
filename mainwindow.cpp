#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QCoreApplication>
#include "Dialog1.h"
#include "Dialog2.h"
#include "dialog3.h"
#include "dialog4.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}



MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_toolButton_clicked()
{
    Dialog1 *infwin=new Dialog1;
    infwin->setWindowTitle("Studentinfo Function Menu");
    infwin->show();
}

void MainWindow::on_toolButton_2_clicked()
{
    Dialog2 *scowin=new Dialog2;
    scowin->setWindowTitle("Studentscore Function Menu");
    scowin->show();
}

void MainWindow::on_toolButton_3_clicked()
{
    Dialog3 *extwin=new Dialog3;
    extwin->setWindowTitle("Extra Function Menu");
    extwin->show();
}

void MainWindow::on_toolButton_4_clicked()
{
   //Dialog4 *quiwin=new Dialog4;
   //quiwin->show();
    this->close();

}
