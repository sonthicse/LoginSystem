#include "../include/Utils.h"
#include <iostream>
#include <cstring>

std::string Utils::hashPassword(const std::string &password)
{
    // Implement a proper hashing algorithm here
    // This is a placeholder and NOT secure
    return password;
}

bool Utils::isValidUsername(const std::string &username)
{
    return username.length() >= MIN_USERNAME_LENGTH && username.length() <= MAX_USERNAME_LENGTH;
}

bool Utils::isValidPassword(const std::string &password)
{
    return password.length() >= MIN_PASSWORD_LENGTH && password.length() <= MAX_PASSWORD_LENGTH;
}

void Utils::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

std::string Utils::getInput(const std::string &prompt)
{
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

std::string Utils::getHiddenInput(const std::string &prompt)
{
    std::string password;
    std::cout << prompt;
#ifdef _WIN32
    char ch;
    while ((ch = _getch()) != '\r')
    {
        if (ch == '\b')
        { // Backspace
            if (!password.empty())
            {
                std::cout << "\b \b";
                password.pop_back();
            }
        }
        else
        {
            password += ch;
            std::cout << '*';
        }
    }
#else
    // Disable echo
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    Copy // Read the password
        std::getline(std::cin, password);

    // Restore echo
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
    std::cout << std::endl;
    return password;
}

UserRole Utils::stringToUserRole(const std::string &roleStr)
{
    if (roleStr == "ADMIN")
        return ADMIN;
    if (roleStr == "REGULAR_USER")
        return REGULAR_USER;
    return GUEST; // Default role
}

std::string Utils::userRoleToString(const UserRole& role)
{
    switch (role)
    {
    case ADMIN:
        return "ADMIN";
    case REGULAR_USER:
        return "REGULAR_USER";
    case GUEST:
        return "GUEST";
    default:
        return "UNKNOWN";
    }
}