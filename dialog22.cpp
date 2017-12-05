#include "dialog22.h"
#include "ui_dialog22.h"
#include "sqlite3.h"
#include "stdio.h"
int id22;
int studentid22;
char* courseid22;
char* coursename22;
int credit22;
int regscore22;
int labscore22;
int examscore22;
extern sqlite3 *pDb;

Dialog22::Dialog22(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog22)
{
    ui->setupUi(this);
}

Dialog22::~Dialog22()
{
    delete ui;
}

void Dialog22::on_pushButton_clicked()
{
    QString str223;
    str223 = this->ui->textEdit->toPlainText();
    bool ok22;
    id22=str223.toInt(&ok22,10);
    ShowScoreById(id22);
}


void Dialog22::ShowScoreById(int id)
{
    int rc;
    char *sql;
    sqlite3_stmt *stmt;
    sql = "SELECT * FROM studentscore WHERE id = ?;";
    rc= sqlite3_prepare_v2(pDb,sql,strlen(sql),&stmt,NULL);
   // printf("rc22 %d\n",rc);
    sqlite3_bind_int(stmt,1,id);
   rc=sqlite3_step(stmt);
   printf("%d",rc);
    while(rc==SQLITE_ROW){
    studentid22= sqlite3_column_int(stmt,1);
    courseid22= (char*)sqlite3_column_text(stmt,2);
    coursename22= (char*) sqlite3_column_text(stmt,3);
    credit22 = sqlite3_column_int(stmt,4);
    regscore22 = sqlite3_column_int(stmt,5);
    labscore22 = sqlite3_column_int(stmt,6);
    examscore22 = sqlite3_column_int(stmt,7);
    printf("%d %d %s %s %d %d %d %d \n",id,studentid22,courseid22,coursename22,credit22,regscore22,labscore22,examscore22);
    QString s221;
    s221.sprintf("\nid %d studentid %d :",id,studentid22);
    ui->textBrowser->append(s221);
    ui->textBrowser->append(QString(QLatin1String(courseid22)));
    ui->textBrowser->append(QString(QLatin1String(coursename22)));
    QString s222;
    s222.sprintf("Score:\n credit :%d  regscore : %d labscore: %d examscore: %d",credit22,regscore22,labscore22,examscore22);
    ui->textBrowser->append(s222);
rc=sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
}
