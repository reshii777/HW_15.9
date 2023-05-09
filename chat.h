#pragma once

#include "sha2.h"
#include <cstring>

#define SIZE 10
#define LOGINLENGTH 10

class Chat {
public:
    Chat();
    void reg(const char _login[LOGINLENGTH], char _pass[], int pass_length);
    bool login(const char _login[LOGINLENGTH], char _pass[], int pass_length);

    friend void test(Chat& c);
private:
    struct AuthData {
        AuthData() :
            login(""),
            pass_sha1_hash(nullptr) {
        }
        ~AuthData() {
            if (pass_sha1_hash != nullptr)
                delete[] pass_sha1_hash;
        }
        AuthData(const char _login[LOGINLENGTH], uint* sh1) {
            strcpy_s(login, _login);
            pass_sha1_hash = sh1;
        }
        AuthData& operator=(const AuthData& other) {
            strcpy_s(login, other.login);

            if (pass_sha1_hash != nullptr)
                delete[] pass_sha1_hash;
            pass_sha1_hash = new uint[SHA1HASHLENGTHUINTS];

            memcpy(pass_sha1_hash, other.pass_sha1_hash, SHA1HASHLENGTHBYTES);

            return *this;
        }
        char login[LOGINLENGTH];
        uint* pass_sha1_hash;
    };
    AuthData data[SIZE];
    int data_count;
};
