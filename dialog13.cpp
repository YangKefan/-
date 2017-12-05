#include "dialog13.h"
#include "ui_dialog13.h"
#include "sqlite3.h"
#include "stdio.h"
extern sqlite3 *pDb;
int id13;
Dialog13::Dialog13(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog13)
{
    ui->setupUi(this);
}

Dialog13::~Dialog13()
{
    delete ui;
}

void Dialog13::on_pushButton_clicked()
{
    QString str13;
    str13=ui->textEdit->toPlainText();
    bool ok13;
    id13=str13.toInt(&ok13,10);
    DeleteInfoById(id13);

}
void  Dialog13::DeleteInfoById(int id)
{
    int rc;
    char *sql;
    sqlite3_stmt * stmt;
    sql = "DELETE FROM studentinfo WHERE id=?";
    sqlite3_prepare_v2(pDb,sql,strlen(sql),&stmt,NULL);
    sqlite3_bind_int(stmt,1,id);
    rc = sqlite3_step(stmt);
    printf("rc13 %d\n",rc);
    if(rc!=101)
        ui->textEdit_2->setText("fail");
    else
       ui->textEdit_2->setText("success");
    sqlite3_finalize(stmt);
}
