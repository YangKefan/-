#ifndef DIALOG11_H
#define DIALOG11_H

#include <QDialog>

namespace Ui {
class Dialog11;
}

class Dialog11 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog11(QWidget *parent = 0);
    ~Dialog11();

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

private:
    Ui::Dialog11 *ui;
};

#endif // DIALOG11_H
