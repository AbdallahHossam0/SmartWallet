/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <wallet.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This header file defines the Wallet class, managing the wallet dialog interface with functionalities for financial transactions,
 *  log management, and input validation.
 * ---------------------------------------------------------------------------------------------------
 */

#ifndef WALLET_H
#define WALLET_H

#include "validator.h"
#include <QDialog>

namespace Ui {
class Wallet;
}

class Wallet : public QDialog {
    Q_OBJECT
      // this method is used to split string by delimeter
    std::vector<std::string> splitString(const std::string &s,
                                         char delimiter = '-');

    // to get the word at specific index on the line
    std::string getWordAtIndex(const std::string &line, int index);

    // to pass all logs to the list
    void parselogsToList(const std::vector<std::string> &strVec);

  public:
    explicit Wallet(int balance, std::string name, QString username,
                    std::string gender, std::string logs,
                    QWidget *parent = nullptr);
    ~Wallet();

  private slots:

    void on_WithdrawButton_clicked();

    void on_DepositButton_clicked();

    void on_TransferButton_clicked();

    void on_RefreshButton_clicked();

    void on_UndoButton_clicked();

    void on_RedoButton_clicked();

  private:
    Ui::Wallet *ui;
    QString m_username;
    Validator m_validator;
};

#endif // WALLET_H
