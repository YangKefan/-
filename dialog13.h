#ifndef DIALOG13_H
#define DIALOG13_H

#include <QDialog>

namespace Ui {
class Dialog13;
}

class Dialog13 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog13(QWidget *parent = 0);
    ~Dialog13();

private slots:
    void on_pushButton_clicked();
    void DeleteInfoById(int id);

private:
    Ui::Dialog13 *ui;
};

#endif // DIALOG13_H
