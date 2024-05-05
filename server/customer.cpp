#include "customer.h"

Customer::Customer(std::string name, std::string username, std::string password,
                   Gender gender)
  : m_name{name}, m_username{username}, m_password{password}, m_gender{gender},
    m_id{id++}, m_balance{0}, isActive{false} {}

unsigned int Customer::getBalance() { return m_balance; }
std::string Customer::getUserName() { return m_username; }
std::string Customer::getName() { return m_name; }
std::string Customer::getGender() {
    switch (m_gender) {
    case Gender::Male:
        return "M";
    case Gender::Female:
        return "F";
    default:
        return "Unknown";
    }
}
int Customer::getID() { return m_id; }

bool Customer::checkPassword(std::string password) {
    return m_password == password;
}

Status Customer::withdraw(int money) {
    if (money > m_balance) {
        return Status::NoBalance;
    } else {
        m_balance -= money;
        log(Operation::Withdraw, std::to_string(money));
        return Status::Done;
    }
}

Status Customer::deposit(int money) {
    m_balance += money;
    log(Operation::Deposit, std::to_string(money));
    return Status::Done;
}

Status Customer::acceptTransfer(int money, Customer &sender) {
    this->m_balance += money;
    log(Operation::AcceptTransfer, std::to_string(money), sender);
    return Status::Done;
}

Status Customer::transfer(int money, Customer &receiver) {
    if (m_balance < money) {
        return Status::NoBalance;
    } else {
        this->m_balance -= money;
        receiver.acceptTransfer(money, *this);
        log(Operation::Transfer, std::to_string(money), receiver);
        return Status::Done;
    }
}
Status Customer::undo(int logID) { return Status::Done; }

Status Customer::redo(int logID) { return Status::Done; }
void Customer::log(Operation op, std::string money) {
    switch (op) {
    case Operation::Withdraw:
        logs.push_back("Withdraw " + money);
        break;
    case Operation::Deposit:
        logs.push_back("Deposit " + money);
        break;
    default:
        break;
    }
}

void Customer::log(Operation op, std::string money, Customer &other) {
    switch (op) {
    case Operation::Transfer:
        logs.push_back("Transfer " + money + " to " + other.getUserName());
        break;
    case Operation::AcceptTransfer:
        logs.push_back("Accept transfer " + money + " from " +
                       other.getUserName());
        break;

    default:
        break;
    }
}