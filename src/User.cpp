#include "../include/User.h"

User::User(const std::string &username, const std::string &password, const UserRole &role)
    : username(username), password(password), role(role) {}

User::~User() {}

User &User::operator=(const User &user)
{
    if (this != &user)
    {
        username = user.username;
        password = user.password;
        role = user.role;
    }
    return *this;
}

bool User::checkPassword(const std::string &inputPassword) const
{
    return inputPassword == password;
}

std::string User::getRoleString() const
{
    switch (role)
    {
    case GUEST:
        return "GUEST";
    case REGULAR_USER:
        return "REGULAR_USER";
    case ADMIN:
        return "ADMIN";
    default:
        return "UNKNOWN";
    }
}

void User::setPassword(const std::string &newPassword)
{
    password = newPassword;
}

void User::setRole(const UserRole &newRole)
{
    role = newRole;
}

UserRole User::getRole() const
{
    return role;
}