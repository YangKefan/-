#include "dialog112.h"
#include "ui_dialog112.h"
#include "sqlite3.h"
#include "qstring.h"
#include <iostream>
#include<stdio.h>
using namespace std;
int id112;
int age112;
char *name112;
char *sex112;
char *phonenum112;
extern sqlite3 * pDb;
Dialog112::Dialog112(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog112)
{
    ui->setupUi(this);
}

Dialog112::~Dialog112()
{
    delete ui;
}

void Dialog112::SearchInfoBYName(char * name)
{
    int rc;
    char *sql;
    sqlite3_stmt * stmt;
    sql = "SELECT * FROM studentinfo WHERE name=?";
    sqlite3_prepare_v2(pDb,sql,strlen(sql),&stmt,NULL);
    sqlite3_bind_text(stmt,1,name,strlen(name),SQLITE_TRANSIENT);
    rc = sqlite3_step(stmt);
    cout<<"rc112:"<<rc<<endl;
    while(rc == SQLITE_ROW)
    {
        id112 = sqlite3_column_int(stmt,0);
        sex112 =(char*) sqlite3_column_text(stmt,2);
        age112 = sqlite3_column_int(stmt,3);
        phonenum112 =(char*)sqlite3_column_text(stmt,4);
        QString s112;
        s112.sprintf("Student id %d informations:",id112);
        ui->textBrowser->append(s112);
        ui->textBrowser->append(QString(QLatin1String(name)));
        ui->textBrowser->append(QString(QLatin1String(sex112)));
        QString s1121;
        s1121.sprintf("%d",age112);
        ui->textBrowser->append(s1121);
        ui->textBrowser->append(QString(QLatin1String(phonenum112)));
        printf(" %d %s %s %d %s \n",id112,name,sex112,age112,phonenum112);
        rc = sqlite3_step(stmt);
    }
    putchar('\n');
    sqlite3_finalize(stmt);
}


void Dialog112::on_toolButton_clicked()
{
    QString str112;
    str112 = this->ui->textEdit->toPlainText();
    std::string str1121 = str112.toStdString();
    name112 = (char*)str1121.c_str();
  SearchInfoBYName(name112);
}
