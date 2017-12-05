#include "dialog111.h"
#include "ui_dialog111.h"
#include "sqlite3.h"
#include "qstring.h"
#include <iostream>
#include<stdio.h>
using namespace std;
int id;
int age;
char *name;
char *sex;
char *phonenum;
extern sqlite3 * pDb;

Dialog111::Dialog111(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog111)
{
    ui->setupUi(this);
}

Dialog111::~Dialog111()
{
    delete ui;
}

void Dialog111:: SearInfoByid(int id)
{
    int rc;
    char *sql;
    sqlite3_stmt *stmt;
    sql = "SELECT * FROM studentinfo WHERE id = ?;";
    sqlite3_prepare_v2(pDb,sql,strlen(sql),&stmt,NULL);
    sqlite3_bind_int(stmt,1,id);
    rc = sqlite3_step(stmt);
    cout<<"rc111:"<<rc<<endl;
    name = (char*)sqlite3_column_text(stmt,1);
    sex =(char*) sqlite3_column_text(stmt,2);
    age = sqlite3_column_int(stmt,3);
    phonenum = (char*)sqlite3_column_text(stmt,4);
    QString s;
    s.sprintf("\nStudent id %d informations:",id);
    ui->textBrowser->append(s);
    ui->textBrowser->append(QString(QLatin1String(name)));
    ui->textBrowser->append(QString(QLatin1String(sex)));
    QString s1;
    s1.sprintf("%d",age);
    ui->textBrowser->append(s1);
    ui->textBrowser->append(QString(QLatin1String(phonenum)));
    printf("%s %s %d %s",name,sex,age,phonenum);
    putchar('\n');
    sqlite3_finalize(stmt);
}

void Dialog111::on_textEdit_destroyed()
{
  // str = this->ui->textEdit->toPlainText();
   // bool ok;
    //id=str.toInt(&ok,10);
}

void Dialog111::on_pushButton_clicked()
{
    QString str;
    str = this->ui->textEdit->toPlainText();
    bool ok;
    id=str.toInt(&ok,10);
    SearInfoByid(id);
    //QString s;
    //s.sprintf("%d|%s|%s|%d|%s\n",id,name,sex,age,phonenum);
    //ui->textBrowser->append(QString(QLatin1String(name)));
    //ui->textBrowser->append(QString(QLatin1String(sex)));
   // ui->textBrowser->append(QString(QLatin1String(phonenum)));
    //this->ui->textBrowser->append(s);

}

void Dialog111::on_textEdit_2_destroyed()
{
    //QString NAME;

    //NAME = QString(QLatin1String(name));
    //this->ui->textEdit_2->setPlainText("NAME");
}
