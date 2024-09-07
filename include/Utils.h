#ifndef UTILS_H
#define UTILS_H

#include "User.h"
#include "UserManager.h"
#include "LoginSystem.h"
#include "config.h"
#include <string>
#include <cstring>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

// Cung cấp các hàm tiện tích cho hệ thống
class Utils {
public:
    static std::string hashPassword(const std::string& password);

    static bool isValidUsername(const std::string& username);
    static bool isValidPassword(const std::string& password);
    
    static void clearScreen();
    
    static std::string getInput(const std::string& prompt);

    static std::string getHiddenInput(const std::string& prompt);

    static UserRole stringToUserRole(const std::string& roleStr);
    static std::string userRoleToString(const UserRole& role);
};

#include "../src/Utils.cpp"

#endif