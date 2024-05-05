#ifndef WALLET_H
#define WALLET_H

#include <QDialog>

namespace Ui {
class Wallet;
}

class Wallet : public QDialog {
    Q_OBJECT

  public:
    explicit Wallet(QWidget *parent = nullptr);
    ~Wallet();

  private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

  private:
    Ui::Wallet *ui;
};

#endif // WALLET_H
