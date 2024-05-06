/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <mainwindow.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This header file defines the MainWindow class, handling the main window interface for the application, including buttons for creating a new wallet and logging in.
 * ---------------------------------------------------------------------------------------------------
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private slots:

    void on_CreateNewWallet_clicked(); // opens the new wallet window

    void on_LoginToWallet_clicked(); // opens the login window

  private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
