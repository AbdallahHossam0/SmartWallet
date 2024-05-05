#include "validator.h"

Validator::Validator() {}

std::string Validator::stripTrailingSpaces(const std::string& str) {
    std::string result = str;
    int index = result.size() - 1;
    while (index >= 0 && result[index] == ' ') {
        result.pop_back();
        index--;
    }
    return result;
}

bool Validator::isValidUsername(std::string username){
    stripTrailingSpaces(username);
    std::regex pattern("^[a-zA-Z0-9_]{5,15}$");
    return std::regex_match(username, pattern);
}
bool Validator::isValidName(std::string name){
    stripTrailingSpaces(name);
    std::regex pattern("^[a-zA-Z]{3,9}$");
    return std::regex_match(name, pattern);
}
bool Validator::isValidPassword(std::string password1){
    std::regex pattern("^[0-9]{6}$");
    return std::regex_match(password1, pattern);
}
bool Validator::isPasswordMatched(std::string password1, std::string password2){
    if(password1 != password2){
        return false;
    }
    else{
        return true;
    }
}
bool Validator::isValidID(std::string id){
    stripTrailingSpaces(id);
    std::regex pattern("^[0-9]{14}$");
    return std::regex_match(id, pattern);
}
bool Validator::isValidMobileNumber(std::string mobileNumber){
    stripTrailingSpaces(mobileNumber);
    std::regex pattern("^01[0-2][0-9]{8}$");
    return std::regex_match(mobileNumber, pattern);
}

bool Validator::isValidMoney(std::string money){
    std::regex pattern("^[0-9]{1,5}$");
    return std::regex_match(money, pattern);
}
