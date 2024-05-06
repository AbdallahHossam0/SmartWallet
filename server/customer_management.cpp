#include "customer_management.h"

std::vector<std::string> CustomerManagement::splitString(const std::string &s,
                                                         char delimiter = '/') {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return move(tokens);
}

bool CustomerManagement::createNewCustomer(std::string name,
                                           std::string username,
                                           std::string password,
                                           Gender gender) {
    if (isUsernameAvailable(username)) {
        customers.insert(
            {username, Customer(name, username, password, gender)});
        return true;
    }
    return false;
}
bool CustomerManagement::signIn(std::string username, std::string password) {
    if (customers.at(username).checkPassword(password)) {
        return true;
    }
    return false;
}

bool CustomerManagement::isUsernameAvailable(std::string username) {
    if (customers.find(username) == customers.end()) {
        return true;
    }
    return false;
}
bool CustomerManagement::isUsernameExists(std::string username) {
    return !isUsernameAvailable(username);
}

std::string CustomerManagement::handleRequests(std::string request) {
    std::vector<std::string> tokens;
    Status s;
    switch (static_cast<Frames>(request[0])) {

    case Frames::NewCustomer:
        tokens = splitString(request);
        if (tokens.size() != 5) {
            return "0";
        }
        if (!createNewCustomer(tokens[1], tokens[2], tokens[3],
                               static_cast<Gender>(tokens[4][0]))) {
            return "1";
        }
        return "11";
        break;

    case Frames::SignIn:
        tokens = splitString(request);
        if (tokens.size() != 3) {
            return "0";
        }
        if (!isUsernameExists(tokens[1])) {
            return "1";
        }
        if (!signIn(tokens[1], tokens[2])) {
            return "2";
        }
        return std::string(
            "11/" + std::to_string(customers.at(tokens[1]).getBalance()) + '/' +
            customers.at(tokens[1]).getName() + '/' +
            customers.at(tokens[1]).getGender() + '/' +
            customers.at(tokens[1]).getLogs());
        break;

    case Frames::Withdraw:
        tokens = splitString(request);
        if (tokens.size() != 3) {
            return "0";
        }
        if (!isUsernameExists(tokens[1])) {
            return "1";
        }

        s = customers.at(tokens[1]).withdraw(stoi(tokens[2]));
        if (s != Status::Done) {
            return "2";
        } else {
            return std::string(
                "11/" + std::to_string(customers.at(tokens[1]).getBalance()) +
                '/' + customers.at(tokens[1]).getLogs());
        }

        break;

    case Frames::Deposit:
        tokens = splitString(request);
        if (tokens.size() != 3) {
            return "0";
        }
        if (!isUsernameExists(tokens[1])) {
            return "1";
        }

        s = customers.at(tokens[1]).deposit(stoi(tokens[2]));
        if (s != Status::Done) {
            return "2";
        } else {
            return std::string(
                "11/" + std::to_string(customers.at(tokens[1]).getBalance()) +
                '/' + customers.at(tokens[1]).getLogs());
        }

        break;

    case Frames::Transfer:
        tokens = splitString(request);
        if (tokens.size() != 4) {
            return "0";
        }
        if (!isUsernameExists(tokens[1])) {
            return "1";
        }
        if (!isUsernameExists(tokens[2])) {
            return "1";
        }
        s = customers.at(tokens[1]).transfer(stoi(tokens[3]),
                                             customers.at(tokens[2]));

        return std::string(
            "11/" + std::to_string(customers.at(tokens[1]).getBalance()) + '/' +
            customers.at(tokens[1]).getLogs());
        break;

    case Frames::Refresh:
        tokens = splitString(request);
        if (tokens.size() != 2) {
            return "0";
        }
        if (!isUsernameExists(tokens[1])) {
            return "1";
        }
        return std::string(
            "11/" + std::to_string(customers.at(tokens[1]).getBalance()) + '/' +
            customers.at(tokens[1]).getLogs());

    default:
        return std::string("0");
        break;
    }
    return std::string("0");
}