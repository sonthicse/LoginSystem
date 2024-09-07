#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H

#include "User.h"
#include "UserManager.h"
#include "LoginSystem.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <limits>

class ConsoleInterface {
private:
    LoginSystem& loginSystem;

public:
    ConsoleInterface(LoginSystem& LoginSystem);
    ~ConsoleInterface();

    void run();

    void showMainMenu();
    void showLoginMenu();
    void showRegisterMenu();

    void handleLogin();
    void handleRegister();
    void handleChangePassword();
    void handleChangeUserRole();

    void displayUserInfo();
    void displayAllUser();
};

#include "../src/ConsoleInterface.cpp"

#endif