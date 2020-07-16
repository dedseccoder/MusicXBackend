#ifndef SINGUPWINDOW_H
#define SINGUPWINDOW_H

#include <QDialog>

namespace Ui {
class SingUpWindow;
}

class SingUpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SingUpWindow(QWidget *parent = nullptr);
    ~SingUpWindow();

private slots:
    void on_Sing_In2_clicked();

private:
    Ui::SingUpWindow *ui;
};

#endif // SINGUPWINDOW_H
