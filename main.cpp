#include "mainwindow.h"
#include <QApplication>
#include "sqlite3.h"
#include "stdio.h"
#include <QtCore/QCoreApplication>
//#include <QTextCodec>
#include "dialog1.h"
#include "dialog11.h"
#include "dialog12.h"
#include "dialog13.h"
#include "dialog2.h"
sqlite3 *pDb;
int openDataBase(){
    int rc;
        char *errmsg;
        rc=sqlite3_open("student.db",&pDb);
        printf("rcmain %d\n",rc);
        if(!rc)
        {
            printf("open database\n");
            return 0;
        }
        else{
            sqlite3_exec(pDb,"PRAGMA foreign_keys=ON",NULL,NULL,&errmsg);
            //printf("open database\n");
            return 1;
        }


}
/*
void setwindowname(){
    Dialog1 w1;
    w1.setWindowTitle("Studentinfo Menu");
    Dialog2 w2;
    w2.setWindowTitle("Studentscore Menu");
    Dialog11 w11;
    w11.setWindowTitle("Search Studeninfo Menu");
    Dialog12 w12;
    w12.setWindowTitle("Insert Studentinfo Menu");
    Dialog13 w13;
    w13.setWindowTitle("Delete Studentinfo Munu");
}
*/
int main(int argc, char *argv[])
{
   // QTextCodec *codec = QTextCodec::codecForName("UTF-8");
  //  QTextCodec::setCodecForLocale(codec);
    openDataBase();
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Function Menu");
    w.show();
    return a.exec();
    }
