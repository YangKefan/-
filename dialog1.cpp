#include "dialog1.h"
#include "ui_dialog1.h"
#include <QtCore/QCoreApplication>
#include "dialog11.h"
#include "dialog12.h"
#include "dialog13.h"
Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}


void Dialog1::on_toolButton_clicked()
{
    Dialog11 *sermenu=new Dialog11;
    sermenu->setWindowTitle("Search Studentinfo Menu");
    sermenu->show();
}

void Dialog1::on_toolButton_2_clicked()
{
    Dialog12 *incmenu = new Dialog12;
    incmenu->setWindowTitle("Insert Studentinfo Menu");
    incmenu->show();
}

void Dialog1::on_toolButton_3_clicked()
{
    Dialog13 * delmenu = new Dialog13;
    delmenu->setWindowTitle("Delete Studentinfo Menu");
    delmenu->show();
}
