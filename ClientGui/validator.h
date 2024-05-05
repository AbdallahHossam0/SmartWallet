#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <regex>


class Validator {
  private:
    std::string stripTrailingSpaces(const std::string& str);
  public:
    Validator();

    bool isValidUsername(std::string username);
    bool isValidName(std::string name);
    bool isValidPassword(std::string password1);
    bool isPasswordMatched(std::string password1, std::string password2);
    bool isValidID(std::string ID);
    bool isValidMobileNumber(std::string mobileNumber);

};

#endif // VALIDATOR_H
