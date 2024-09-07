#include "../include/LoginSystem.h"
#include "../include/ConsoleInterface.h"

int main() {
    LoginSystem loginSystem;
    ConsoleInterface consoleInterface(loginSystem);

    consoleInterface.run();
}