/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <mainwindow.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This header file declares the MainWindow class, responsible for managing the main window interface of the application
 *  and providing methods for updating its components.
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

    void updateActiveUsers();
    void updateUserLog();
    void updateOperation();
    void updateWithdraws();
    void updateDeposits();

  private:
    void Update();

    Ui::MainWindow *ui;
    QTimer *timer;
};
#endif // MAINWINDOW_H
