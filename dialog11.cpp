#include "dialog11.h"
#include "ui_dialog11.h"
#include <QtCore/QCoreApplication>
#include "dialog111.h"
#include "dialog112.h"
#include "dialog113.h"
Dialog11::Dialog11(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog11)
{
    ui->setupUi(this);
}

Dialog11::~Dialog11()
{
    delete ui;
}

void Dialog11::on_toolButton_clicked()
{
    Dialog111 *idwin=new Dialog111;
    idwin->setWindowTitle("Searchinfo By ID");
    idwin->show();
}

void Dialog11::on_toolButton_2_clicked()
{
    Dialog112 *namewin=new Dialog112;
    namewin->setWindowTitle("Searchinfo By Name");
    namewin->show();

}

void Dialog11::on_toolButton_3_clicked()
{
   Dialog113  *sexwin=new Dialog113;
   sexwin->setWindowTitle("Searchinfo By Sex");
   sexwin->show();
}
