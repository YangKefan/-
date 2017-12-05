#include "dialog2.h"
#include "ui_dialog2.h"
#include <QtCore/QCoreApplication>
#include "dialog21.h"
#include "dialog22.h"
#include "dialog23.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2()
{
    delete ui;
}
void Dialog2::on_toolButton_clicked()
{
    Dialog21 *incscore=new Dialog21;
    incscore->setWindowTitle("Insert Studentscore Menu");
    incscore->show();
}
void Dialog2::on_toolButton_2_clicked()
{
    Dialog22 *serscore=new Dialog22;
    serscore->setWindowTitle("Search Studentscore Menu");
    serscore->show();
}
void Dialog2::on_toolButton_3_clicked()
{
    Dialog23 *sortscore=new Dialog23;
    sortscore->setWindowTitle("Sort Studentscore Menu");
    sortscore->show();
}
void Dialog2::on_toolButton_4_clicked()
{
    this->close();
}
