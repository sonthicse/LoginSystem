#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "Utils.h"
#include "config.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Quản lí tất cả người dùng trong hệ thống
class UserManager {
private:
    std::vector<User> users;
    void loadUsers();
    void saveUsers() const;

public:
    UserManager();
    ~UserManager();

    bool addUser(const User& user);
    bool removeUser(const std::string& username);
    User* findUser(const std::string& username);

    bool isUsernameTaken(const std::string& username);
    
    std::vector<User> getUsersByRole(const UserRole& role) const;
};

#include "../src/UserManager.cpp"

#endif