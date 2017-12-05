#include "dialog12.h"
#include "ui_dialog12.h"
#include "sqlite3.h"
#include "stdio.h"
extern sqlite3 *pDb;

int Dialog12::InsertStudentInfo(int id,char* name,char* sex,int age,char *phonenum)
{
    char* sql;
    const char* tail;
    sqlite3_stmt * stmt;
    int rc;
    sql="INSERT INTO studentinfo(id,name,sex,age,phonenum)" "VALUES(?,?,?,?,?)";
    rc=sqlite3_prepare_v2(pDb,sql,strlen(sql),&stmt,&tail);
    printf("rc12 %d\n",rc);
    sqlite3_bind_int(stmt,1,id);
    sqlite3_bind_text(stmt,2,name,strlen(name),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,3,sex,strlen(sex),SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt,4,age);
    sqlite3_bind_text(stmt,5,phonenum,strlen(phonenum),SQLITE_TRANSIENT);
    if(rc)
    {
        printf("error exiting0\n");
        sqlite3_finalize(stmt);
        return 0;
    }
    if(sqlite3_step(stmt)!=SQLITE_DONE)
    {
        printf("error exiting1\n");
        sqlite3_finalize(stmt);
        return 0;
    }
    sqlite3_finalize(stmt);
    return 1;
}

Dialog12::Dialog12(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog12)
{
    ui->setupUi(this);
}

Dialog12::~Dialog12()
{
    delete ui;
}
void Dialog12::on_pushButton_clicked()
{
    int id12;
    char *name12;
    char *sex12;
    int age12;
    char *phonenum12;
   int flag;

   QString str121;
   str121=ui->textEdit->toPlainText();
   bool ok12;
   id12=str121.toInt(&ok12,10);

   QString str122;
   str122=ui->textEdit_2->toPlainText();
   QByteArray b12=str122.toLatin1();
   name12 =b12.data();

   QString str123;
   str123=ui->textEdit_3->toPlainText();
   QByteArray c12 = str123.toLatin1();
   sex12 = c12.data();

   QString str124;
   str124=ui->textEdit_4->toPlainText();
   bool ok121;
   age12=str124.toInt(&ok121,10);

   QString str125;
   str125=ui->textEdit_5->toPlainText();
   QByteArray a12=str125.toLatin1();
   phonenum12=a12.data();


   flag=InsertStudentInfo(id12,name12,sex12,age12,phonenum12);
   if(flag){
       this->ui->textEdit_6->setText("success");
   }else{
       this->ui->textEdit_6->setText("fail");
   }

}
