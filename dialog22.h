#ifndef DIALOG22_H
#define DIALOG22_H

#include <QDialog>

namespace Ui {
class Dialog22;
}

class Dialog22 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog22(QWidget *parent = 0);
    ~Dialog22();

private slots:
    void on_pushButton_clicked();
    void ShowScoreById(int id);
private:
    Ui::Dialog22 *ui;
};

#endif // DIALOG22_H
