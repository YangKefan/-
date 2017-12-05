#include "dialog113.h"
#include "ui_dialog113.h"
#include "sqlite3.h"
#include "qstring.h"
#include <iostream>
#include<stdio.h>
using namespace std;
int id113;
int age113;
char *name113;
char *sex113;
char *phonenum113;
extern sqlite3 * pDb;
Dialog113::Dialog113(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog113)
{
    ui->setupUi(this);
}

Dialog113::~Dialog113()
{
    delete ui;
}

void Dialog113::SearchInfoByAge(int age)
{
    int rc;
    char *sql;
    sqlite3_stmt * stmt;
    sql="SELECT * FROM studentinfo WHERE age=?";
    sqlite3_prepare_v2(pDb,sql,strlen(sql),&stmt,NULL);
    sqlite3_bind_int(stmt,1,age);
    rc = sqlite3_step(stmt);
    cout<<"rc113: "<<rc<<endl;
    while(rc == SQLITE_ROW)
    {
        id113 = sqlite3_column_int(stmt,0);
        name113 = (char*)sqlite3_column_text(stmt,1);
        sex113 = (char*)sqlite3_column_text(stmt,2);
        phonenum113 = (char*)sqlite3_column_text(stmt,4);
        QString s113;
        s113.sprintf("Student id %d informations: ",id113);
        ui->textBrowser->append(s113);
        ui->textBrowser->append(QString(QLatin1String(name113)));
        ui->textBrowser->append(QString(QLatin1String(sex113)));
        QString s1131;
        s1131.sprintf("%d",age);
        ui->textBrowser->append(s1131);
        ui->textBrowser->append(QString(QLatin1String(phonenum113)));
        printf("%s %s %d %s",name113,sex113,age113,phonenum113);
        rc = sqlite3_step(stmt);
    }
    putchar('\n');
    sqlite3_finalize(stmt);
}
void Dialog113::on_toolButton_clicked()
{
    QString str;
    str = this->ui->textEdit->toPlainText();
    bool ok;
    age113=str.toInt(&ok,10);
    SearchInfoByAge(age113);

}
