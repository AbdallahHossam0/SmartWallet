/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <signin.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This header file defines the SignIn class, managing the sign-in dialog interface, including login functionality and navigation controls.
 * ---------------------------------------------------------------------------------------------------
 */

#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>

namespace Ui {
class SignIn;
}

class SignIn : public QDialog {
    Q_OBJECT

    // this method is used to split string by delimeter
    std::vector<std::string> splitString(const std::string &s,
                                         char delimiter = '-');

  public:
    explicit SignIn(QWidget *parent = nullptr);
    ~SignIn();

  private slots:
    void on_LoginButton_clicked(); // to process the login

    void on_BackToMainWindow_clicked(); // to go back to the main window

  private:
    Ui::SignIn *ui;
};

#endif // SIGNIN_H
