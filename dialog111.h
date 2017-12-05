#ifndef DIALOG111_H
#define DIALOG111_H

#include <QDialog>

namespace Ui {
class Dialog111;
}

class Dialog111 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog111(QWidget *parent = 0);
    ~Dialog111();

private slots:
     void SearInfoByid(int id);
    void on_textEdit_destroyed();

    void on_pushButton_clicked();

    void on_textEdit_2_destroyed();

private:
    Ui::Dialog111 *ui;
};

#endif // DIALOG111_H
