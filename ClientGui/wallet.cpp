#include "wallet.h"
#include "ui_wallet.h"

Wallet::Wallet(QWidget *parent) : QDialog(parent), ui(new Ui::Wallet) {
    ui->setupUi(this);
}

Wallet::~Wallet() { delete ui; }

void Wallet::on_pushButton_clicked()
{

}


void Wallet::on_pushButton_2_clicked()
{

}


void Wallet::on_pushButton_3_clicked()
{

}

