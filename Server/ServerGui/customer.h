/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <customer.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This header file defines the Customer class, encapsulating user data and transaction functionalities.
 * ---------------------------------------------------------------------------------------------------
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>

enum class Gender : char { Male = 'M', Female = 'F' };
enum class Status : char { Done = 0, NoBalance, UsernameNotFound, Other };
enum class Operation : char { Withdraw, Deposit, Transfer, AcceptTransfer };

class Customer {
  private:
    Gender m_gender;
    int m_id;
    int m_balance;
    std::string m_name;
    std::string m_username;
    std::string m_password;
    std::vector<std::string> logs;
    bool isActive;

    inline static int id = 0;

  public:
    Customer() = delete;

    explicit Customer(std::string Name, std::string username,
                      std::string password, Gender gender);

    unsigned int getBalance();
    std::string getUserName();
    std::string getName();
    std::string getGender();
    int getID();
    bool checkPassword(std::string password);
    Status withdraw(int money);
    Status deposit(int money);
    Status acceptTransfer(int money, Customer &sender);
    Status transfer(int money, Customer &customer);
    Status undo(int logID);
    Status redo(int logID);
    void log(Operation op, std::string money);
    void log(Operation op, std::string money, Customer &other);

    std::string getLogs() {
        std::string res{""};
        for (auto &log : logs) {
            res = res + log + "-";
        }
        return res;
    }
};
