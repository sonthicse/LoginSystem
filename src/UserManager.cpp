#include "../include/UserManager.h"

void UserManager::loadUsers()
{
    std::ifstream userFile(userFilePath);
    if(userFile.is_open())
    {
        std::string line;

        while (getline(userFile, line))
        {
            std::stringstream ss(line);
            std::string username, password, role;
            ss >> username >> password >> role;

            users.push_back(User(username, password, Utils::stringToUserRole(role)));
        }
    }
    else
    {
        std::cerr << "Unable to open users.dat for reading" << std::endl;
    }
}

void UserManager::saveUsers() const
{
    std::ofstream userFile(userFilePath);
    if(userFile.is_open())
    {
        for (const auto &user : users)
        {
            userFile << user.username << ' ' << user.password << ' ' << user.getRoleString() << '\n';
        }
    }
    else
    {
        std::cerr << "Unable to open users.dat for writing" << std::endl;
    }
}

UserManager::UserManager()
{
    loadUsers();
}

UserManager::~UserManager()
{
    saveUsers();
}

bool UserManager::addUser(const User &user)
{
    if (!isUsernameTaken(user.username))
    {
        users.push_back(user);
        return true;
    }

    return false;
}

bool UserManager::removeUser(const std::string &username)
{
    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if (username == it->username)
        {
            users.erase(it);
            return true;
        }
    }

    return false;
}

User *UserManager::findUser(const std::string &username)
{
    for (auto &user : users)
    {
        if (username == user.username)
        {
            return &user;
        }
    }

    return nullptr;
}

bool UserManager::isUsernameTaken(const std::string &username)
{
    return findUser(username) != nullptr;
}

std::vector<User> UserManager::getUsersByRole(const UserRole &role) const
{
    std::vector<User> usersByRole;
    
    for(const auto &user : users)
    {
        if (role == user.getRole())
        {
            usersByRole.push_back(user);
        }
    }

    return usersByRole;
}