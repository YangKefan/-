#include "dialog21.h"
#include "ui_dialog21.h"
#include "sqlite3.h"
#include "stdio.h"
extern sqlite3 *pDb;
Dialog21::Dialog21(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog21)
{
    ui->setupUi(this);
}

Dialog21::~Dialog21()
{
    delete ui;
}
int Dialog21::InsertStudentScore(int id,int studentid,char* courseid,char* coursename,int credit,int regscore,int labscore,int examscore)
{
    char *sql;
    const char* tail;
    sqlite3_stmt *stmt;
    int rc;
    sql="INSERT INTO studentscore(id,studentid,courseid,coursename,credit,regscore,labscore,examscore)""VALUES(?,?,?,?,?,?,?,?)";
    rc=sqlite3_prepare_v2(pDb,sql,strlen(sql),&stmt,&tail);
    printf("rc21 %d\n",rc);
    if(rc)
    {
        sqlite3_finalize(stmt);
        return 0;
    }
    sqlite3_bind_int(stmt,1,id);
    sqlite3_bind_int(stmt,2,studentid);
    sqlite3_bind_text(stmt,3,courseid,strlen(courseid),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,4,coursename,strlen(coursename),SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt,5,credit);
    sqlite3_bind_int(stmt,6,regscore);
    sqlite3_bind_int(stmt,7,labscore);
    sqlite3_bind_int(stmt,8,examscore);
    if(sqlite3_step(stmt)!=SQLITE_DONE)
    {
        sqlite3_finalize(stmt);
        return 0;
    }
    return 1;
}

void Dialog21::on_toolButton_clicked()
{
    int id21;
    int studentid21;
    char* courseid21;
    char* coursename21;
    int credit21;
    int regscore21;
    int labscore21;
    int examscore21;
  int flag;
  QString str211;
  str211=this->ui->lineEdit->text();
  bool ok211;
  id21=str211.toInt(&ok211,10);

  QString str212;
  str212=ui->lineEdit_2->text();
  bool ok212;
  studentid21=str212.toInt(&ok212,10);

  QString str213;
  str213=ui->lineEdit_3->text();
  QByteArray a=str213.toLatin1();
  courseid21=a.data();

  QString str214;
  str214=ui->lineEdit_4->text();
  QByteArray b = str214.toLatin1();
  coursename21 =b.data();


  QString str215;
  str215=ui->lineEdit_5->text();
  bool ok215;
  credit21=str215.toInt(&ok215,10);

  QString str216;
  str216=ui->lineEdit_6->text();
  bool ok216;
  regscore21=str216.toInt(&ok216,10);

  QString str217;
  str217=ui->lineEdit_7->text();
  bool ok217;
  labscore21=str217.toInt(&ok217,10);

  QString str218;
  str218=ui->textEdit_2->toPlainText();
  bool ok218;
  examscore21=str218.toInt(&ok218,10);
  flag=InsertStudentScore(id21,studentid21,courseid21,coursename21,credit21,regscore21,labscore21,examscore21);
  if(flag)
     this->ui->textEdit->setText("success");
  else
     this->ui->textEdit->setText("error");
}
