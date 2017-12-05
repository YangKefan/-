#ifndef DIALOG23_H
#define DIALOG23_H

#include <QDialog>

namespace Ui {
class Dialog23;
}

class Dialog23 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog23(QWidget *parent = 0);
    ~Dialog23();

private slots:
    void on_pushButton_clicked();
    void SortByScore();
    void ShowScoreById(int id);
private:
    Ui::Dialog23 *ui;
};

#endif // DIALOG23_H
