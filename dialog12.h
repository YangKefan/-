#ifndef DIALOG12_H
#define DIALOG12_H

#include <QDialog>

namespace Ui {
class Dialog12;
}

class Dialog12 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog12(QWidget *parent = 0);
    ~Dialog12();

private slots:
    void on_pushButton_clicked();
    int InsertStudentInfo(int id,char* name,char* sex,int age,char *phonenum);

private:
    Ui::Dialog12 *ui;
};

#endif // DIALOG12_H
