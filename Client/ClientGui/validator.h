/* File Comment
 * ---------------------------------------------------------------------------------------------------
 * [FILE NAME]: <validator.h>
 *
 * [AUTHOR]: Abdallah Hossam-Eldin Hosni
 *
 * [DESCRIPTION]: This header file defines the Validator class, providing methods for string validation.
 * ---------------------------------------------------------------------------------------------------
 */

#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <regex>
#include <string>

class Validator {
  private:
    std::string stripTrailingSpaces(const std::string &str);

  public:
    Validator();

    bool isValidUsername(std::string username);
    bool isValidName(std::string name);
    bool isValidPassword(std::string password1);
    bool isPasswordMatched(std::string password1, std::string password2);
    bool isValidID(std::string ID);
    bool isValidMobileNumber(std::string mobileNumber);
    bool isValidMoney(std::string money);
};

#endif // VALIDATOR_H
