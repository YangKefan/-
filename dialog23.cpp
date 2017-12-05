#include "dialog23.h"
#include "ui_dialog23.h"
#include "sqlite3.h"
#include "QString.h"
#include <iostream>
#include <stdio.h>
extern sqlite3 *pDb;
Dialog23::Dialog23(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog23)
{
    ui->setupUi(this);
}

Dialog23::~Dialog23()
{
    delete ui;
}
void Dialog23::ShowScoreById(int id)
{
    int rc;
      char * sql;
      int courseId;
      const unsigned char * courseName;
      char *courseName1;
      int totalScore,credit;
      sqlite3_stmt *stmt;
          sql = "SELECT courseid,coursename,examscore,credit FROM studentscore WHERE id=?";
          sqlite3_prepare(pDb,sql,strlen(sql),&stmt,NULL);
          sqlite3_bind_int(stmt,1,id);
          rc = sqlite3_step(stmt);
          while(rc == SQLITE_ROW)
          {
              courseId =sqlite3_column_int(stmt,0);
              courseName = sqlite3_column_text(stmt,1);
              totalScore = sqlite3_column_int(stmt,2);
              credit = sqlite3_column_int(stmt,3);
              QString a,b,c,d;
             a.sprintf("%d",id);
             b.sprintf("%d",courseId);
             c.sprintf("%d",totalScore);
             d.sprintf("%d",credit);
             courseName1=(char*)courseName;
             ui->textBrowser->append("Id:  "+a);
             ui->textBrowser->append("courseId:  "+b);
             ui->textBrowser->append("courseName:  "+QString(QLatin1String(courseName1)));
              ui->textBrowser->append("totalscore  :"+c);
              ui->textBrowser->append("credit:  "+d);
              rc = sqlite3_step(stmt);
          }
          sqlite3_finalize(stmt);
         putchar('\n');

}
void Dialog23::SortByScore()
{
int rc;
char *sql;
int studentID;
sqlite3_stmt *stmt;
sql="SELECT id,examscore FROM studentscore GROUP BY id ORDER BY examscore DESC";
sqlite3_prepare(pDb,sql,strlen(sql),&stmt,NULL);
rc=sqlite3_step(stmt);
printf("%d",rc);
while(rc==SQLITE_ROW){

     studentID=sqlite3_column_int(stmt,0); printf("%d\n",studentID);
     ShowScoreById(studentID);
     rc=sqlite3_step(stmt);
}
sqlite3_finalize(stmt);
}

void Dialog23::on_pushButton_clicked()
{
SortByScore();
}
