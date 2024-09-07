#include "../include/LoginSystem.h"

LoginSystem::LoginSystem() : userManager(UserManager()), currentUser(nullptr) {}

LoginSystem::~LoginSystem()
{
    logout();
}

bool LoginSystem::login(const std::string &username, const std::string &password)
{
    User *user = userManager.findUser(username);
    if (user && user->checkPassword(password))
    {
        currentUser = user;
        return true;
    }

    return false;
}

bool LoginSystem::registerUser(const std::string &username, const std::string &password, const std::string &role)
{
    if (!Utils::isValidUsername(username) || !Utils::isValidPassword(password))
    {
        return false;
    }

    User newUser(username, password, Utils::stringToUserRole(role));

    return userManager.addUser(newUser);
}

bool LoginSystem::changePassword(const std::string &oldPassword, const std::string &newPassword)
{
    if (!currentUser)
    {
        return false;
    } else {
        if (currentUser->checkPassword(oldPassword)) {
            currentUser->setPassword(newPassword);
            return true;
        } else {
            return false;
        }
    }
}

void LoginSystem::logout()
{
    currentUser = nullptr;
}

bool LoginSystem::isLoggedIn() const
{
    return currentUser != nullptr;
}

bool LoginSystem::changeUserRole(const std::string &username, const std::string &role)
{
    if (!currentUser || currentUser->getRole() != ADMIN)
    {
        return false;
    }

    User *user = userManager.findUser(username);

    if (user)
    {
        user->setRole(Utils::stringToUserRole(role));
        return true;
    }

    return false;
}

User *LoginSystem::getCurrentUser() const
{
    return currentUser;
}