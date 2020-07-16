#ifndef SINGINWINDOW_H
#define SINGINWINDOW_H

#include <QDialog>

namespace Ui {
class SingInWindow;
}

class SingInWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SingInWindow(QWidget *parent = nullptr);
    ~SingInWindow();

private slots:
    void on_Sing_In_clicked();

private:
    Ui::SingInWindow *ui;
};

#endif // SINGINWINDOW_H
