#ifndef DIALOG112_H
#define DIALOG112_H

#include <QDialog>

namespace Ui {
class Dialog112;
}

class Dialog112 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog112(QWidget *parent = 0);
    ~Dialog112();

private slots:
    void on_toolButton_clicked();
    void SearchInfoBYName(char * name);

private:
    Ui::Dialog112 *ui;
};

#endif // DIALOG112_H
