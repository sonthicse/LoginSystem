#ifndef USER_H
#define USER_H

#include <string>

enum UserRole {ADMIN, REGULAR_USER, GUEST};

// Đại diện cho một người dùng trong hệ thống
class User {
private:
    std::string username;
    std::string password;
    UserRole role;

public:
    User(const std::string& username, const std::string& password, const UserRole& role);
    User& operator=(const User& user);
    ~User();

    void setPassword(const std::string& newPassword);
    void setRole(const UserRole& role);

    bool checkPassword(const std::string& inputPassword) const;
    std::string getRoleString() const;
    UserRole getRole() const;

    friend class UserManager;

    friend class LoginSystem;
};

#include "../src/User.cpp"

#endif