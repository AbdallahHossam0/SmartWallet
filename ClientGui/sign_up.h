#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <QDialog>

namespace Ui {
class Sign_Up;
}

class Sign_Up : public QDialog {
    Q_OBJECT

  public:
    explicit Sign_Up(QWidget *parent = nullptr);
    ~Sign_Up();

  private slots:
    void on_BackToMainWindow_clicked();

    void on_SignUpButton_clicked();

  private:
    Ui::Sign_Up *ui;
};

#endif // SIGN_UP_H
