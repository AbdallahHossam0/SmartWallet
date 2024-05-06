/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <sign_up.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This header file defines the Sign_Up class, managing the sign-up dialog interface, including navigation and sign-up functionality.
 * ---------------------------------------------------------------------------------------------------
 */

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
    void on_BackToMainWindow_clicked(); // to get back the initial window

    void on_SignUpButton_clicked(); // to proceed the sign up

  private:
    Ui::Sign_Up *ui;
};

#endif // SIGN_UP_H
