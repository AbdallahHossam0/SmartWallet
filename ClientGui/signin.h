#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>

namespace Ui {
class SignIn;
}

class SignIn : public QDialog {
    Q_OBJECT

  public:
    explicit SignIn(QWidget *parent = nullptr);
    ~SignIn();

  private slots:
    void on_LoginButton_clicked();

    void on_BackToMainWindow_clicked();

  private:
    Ui::SignIn *ui;
};

#endif // SIGNIN_H
