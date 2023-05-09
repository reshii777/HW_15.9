#include <iostream>
#include <string.h>
#include "chat.h"

#define _CRT_SECURE_NO_WARNINGS


int main() {

    setlocale(LC_ALL, "ru_RU");

    Chat chat;

    // Регистрация пользователей
    chat.reg(const_cast<char*>("user1"), const_cast<char*>("password1"), strlen("password1"));
    chat.reg(const_cast<char*>("user2"), const_cast<char*>("password2"), strlen("password2"));
    chat.reg(const_cast<char*>("user3"), const_cast<char*>("password3"), strlen("password3"));

    // Попытка логина с верными и неверными данными
    if (chat.login(const_cast<char*>("user1"), const_cast<char*>("password1"), strlen("password1"))) {
        std::cout << "Успешный вход для пользователя1" << std::endl;
    }
    else {
        std::cout << "Неудачный вход для пользователя1" << std::endl;
    }

    if (chat.login(const_cast<char*>("user2"), const_cast<char*>("wrongpassword"), strlen("wrongpassword"))) {
        std::cout << "Успешный вход для пользователя2" << std::endl;
    }
    else {
        std::cout << "Неудачный вход для пользователя2" << std::endl;
    }

    if (chat.login(const_cast<char*>("user3"), const_cast<char*>("password3"), strlen("password3"))) {
        std::cout << "Успешный вход для пользователя3" << std::endl;
    }
    else {
        std::cout << "Неудачный вход для пользователя3" << std::endl;
    }

    return 0;
}
