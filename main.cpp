#include <iostream>
#include <string.h>
#include "chat.h"

#define _CRT_SECURE_NO_WARNINGS


int main() {

    setlocale(LC_ALL, "ru_RU");

    Chat chat;

    // ����������� �������������
    chat.reg(const_cast<char*>("user1"), const_cast<char*>("password1"), strlen("password1"));
    chat.reg(const_cast<char*>("user2"), const_cast<char*>("password2"), strlen("password2"));
    chat.reg(const_cast<char*>("user3"), const_cast<char*>("password3"), strlen("password3"));

    // ������� ������ � ������� � ��������� �������
    if (chat.login(const_cast<char*>("user1"), const_cast<char*>("password1"), strlen("password1"))) {
        std::cout << "�������� ���� ��� ������������1" << std::endl;
    }
    else {
        std::cout << "��������� ���� ��� ������������1" << std::endl;
    }

    if (chat.login(const_cast<char*>("user2"), const_cast<char*>("wrongpassword"), strlen("wrongpassword"))) {
        std::cout << "�������� ���� ��� ������������2" << std::endl;
    }
    else {
        std::cout << "��������� ���� ��� ������������2" << std::endl;
    }

    if (chat.login(const_cast<char*>("user3"), const_cast<char*>("password3"), strlen("password3"))) {
        std::cout << "�������� ���� ��� ������������3" << std::endl;
    }
    else {
        std::cout << "��������� ���� ��� ������������3" << std::endl;
    }

    return 0;
}
