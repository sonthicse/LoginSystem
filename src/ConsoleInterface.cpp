#include "../include/ConsoleInterface.h"

ConsoleInterface::ConsoleInterface(LoginSystem &loginSystem) : loginSystem(loginSystem) {}

ConsoleInterface::~ConsoleInterface() {
    loginSystem.~LoginSystem();
}

void ConsoleInterface::run()
{
    while (true)
    {
        showMainMenu();
    }
}

void ConsoleInterface::showMainMenu()
{
    Utils::clearScreen();
    std::cout << "\t\t\t--------------------------------\n"
                 "\t\t\t      LOGIN SYSTEM PROJECT      \n"
                 "\t\t\t--------------------------------\n"
                 "\t\t\t\t1. Login                      \n"
                 "\t\t\t\t2. Register                   \n"
                 "\t\t\t\t0. EXIT                       \n"
                 "\t\t\t--------------------------------\n";
    std::string choice = Utils::getInput("Enter your choice: ");

    if (choice == "0")
    {
        ConsoleInterface::~ConsoleInterface();
        exit(0);
    }
    else if (choice == "1")
    {
        handleLogin();
    }
    else if (choice == "2")
    {
        handleRegister();
    }
    else
    {
        std::cout << "Invalid choice. Please try again.\n";
    }
}

void ConsoleInterface::handleLogin()
{
    Utils::clearScreen();
    std::string username = Utils::getInput("Enter username: ");
    std::string password = Utils::getHiddenInput("Enter password: ");
    if (loginSystem.login(username, password))
    {
        std::cout << "Login successful!\n";
        getch();
        if (loginSystem.getCurrentUser()->getRole() == ADMIN)
        {
            // showAdminMenu();
        }
        else
        {
            // showUserMenu();
        }
    }
    else
    {
        std::cout << "Login failed. Invalid username or password.\n";
        getch();
    }
}

void ConsoleInterface::handleRegister()
{
    Utils::clearScreen();
    std::string username = Utils::getInput("Enter new username: ");
    std::string password = Utils::getHiddenInput("Enter new password: ");
    std::string confirmPassword = Utils::getHiddenInput("Confirm password: ");
    if (password != confirmPassword)
    {
        std::cout << "Passwords do not match. Registration failed.\n";
        return;
    }

    if (loginSystem.registerUser(username, password, "REGULAR_USER"))
    {
        std::cout << "Registration successful!\n";
        getch();
    }
    else
    {
        std::cout << "Registration failed. Username may already exist.\n";
        getch();
    }
}
