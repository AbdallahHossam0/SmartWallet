/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <validator.cpp>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This source file defines the Validator class, providing methods for string validation.
 * ---------------------------------------------------------------------------------------------------
 */

#include "validator.h"

Validator::Validator() {}

std::string Validator::stripTrailingSpaces(const std::string &str) {
    std::string result = str;
    int index = result.size() - 1;
    while (index >= 0 && result[index] == ' ') {
        result.pop_back();
        index--;
    }
    return result;
}

// checks the username
bool Validator::isValidUsername(std::string username) {
    stripTrailingSpaces(username);
    // username available size is from 3 to 15 and the only letters and numbers and underscores
    std::regex pattern("^[a-zA-Z0-9_]{3,15}$");
    return std::regex_match(username, pattern);
}

// validate the name of the user
bool Validator::isValidName(std::string name) {
    stripTrailingSpaces(name);
    // only letters available
    std::regex pattern("^[a-zA-Z]{3,9}$");
    return std::regex_match(name, pattern);
}
// validate the password, it should be 6 numbers
bool Validator::isValidPassword(std::string password1) {
    std::regex pattern("^[0-9]{6}$");
    return std::regex_match(password1, pattern);
}
//check if passwords are matched
bool Validator::isPasswordMatched(std::string password1,
                                  std::string password2) {
    if (password1 != password2) {
        return false;
    } else {
        return true;
    }
}
// check the national id
bool Validator::isValidID(std::string id) {
    stripTrailingSpaces(id);
    std::regex pattern("^[0-9]{14}$");
    return std::regex_match(id, pattern);
}
// check the mobile number
bool Validator::isValidMobileNumber(std::string mobileNumber) {
    stripTrailingSpaces(mobileNumber);
    std::regex pattern("^01[0-2][0-9]{8}$");
    return std::regex_match(mobileNumber, pattern);
}
// check is this string can represend money
bool Validator::isValidMoney(std::string money) {
    std::regex pattern("^[0-9]{1,5}$");
    return std::regex_match(money, pattern);
}
