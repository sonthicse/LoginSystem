#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H

#include "UserManager.h"
#include "User.h"
#include "Utils.h"
#include "config.h"

// Xử lí quá trình đăng nhập, đằng kí và quản lí tài khoản
class LoginSystem {
private:
    UserManager userManager;
    User* currentUser;

public:
    LoginSystem();
    ~LoginSystem();

    User* getCurrentUser() const;

    bool login(const std::string& username, const std::string& password);
    bool registerUser(const std::string& username, const std::string& password, const std::string& role);
    bool changePassword(const std::string& oldPassword, const std::string& newPassword);

    void logout();
    bool isLoggedIn() const;
    bool changeUserRole(const std::string &username, const std::string &role);
};

#include "../src/LoginSystem.cpp"

#endif