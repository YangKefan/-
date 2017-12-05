#ifndef DIALOG21_H
#define DIALOG21_H

#include <QDialog>

namespace Ui {
class Dialog21;
}

class Dialog21 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog21(QWidget *parent = 0);
    ~Dialog21();

private slots:
    int InsertStudentScore(int id,int studentid,char* courseid,char* coursename,int credit,int regscore,int labscore,int examscore);
    void on_toolButton_clicked();

private:
    Ui::Dialog21 *ui;
};

#endif // DIALOG21_H
