#ifndef DIALOG113_H
#define DIALOG113_H

#include <QDialog>

namespace Ui {
class Dialog113;
}

class Dialog113 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog113(QWidget *parent = 0);
    ~Dialog113();

private slots:
    void on_toolButton_clicked();
    void SearchInfoByAge(int age);

private:
    Ui::Dialog113 *ui;
};

#endif // DIALOG113_H
