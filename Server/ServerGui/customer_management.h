/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <customer_management.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This header file defines the CustomerManagement class, which manages customer data and
 *  handles various requests such as creating new customers, signing in, and processing financial transactions.
 * ---------------------------------------------------------------------------------------------------
 */


#pragma once

#include "customer.h"
#include <map>
#include <sstream>
#include <string>
#include <vector>

enum class Frames : char {
    NewCustomer = '0',
    SignIn = '1',
    Withdraw = '2',
    Deposit = '3',
    Transfer = '4',
    Refresh = '5'
};

class CustomerManagement {
  private:
    std::map<std::string, Customer> customers;

    std::vector<std::string> splitString(const std::string &s, char delimiter);

    CustomerManagement() {}

    CustomerManagement(const CustomerManagement &) = delete;
    CustomerManagement &operator=(const CustomerManagement &) = delete;

    bool createNewCustomer(std::string name, std::string username,
                           std::string password, Gender gender);
    bool signIn(std::string username, std::string password);

    bool isUsernameAvailable(std::string username);
    bool isUsernameExists(std::string username);

  public:
    std::string handleRequests(std::string request);
    static CustomerManagement &getCustomerManager() {
        static CustomerManagement customerManager;
        return customerManager;
    }
};
