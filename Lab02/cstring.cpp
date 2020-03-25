/* 
 * File:   cstring.cpp
 * Author: Andres Moreno , Simon Walther
 * 
 * Created on March 7, 2020, 2:44 PM
 */

#include "cstring.hpp"
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

String::String() {
    createString("");
}

String::String(const char *str) {
    createString(str);
}

String::String(const String &str) : String(str.value) {}

String::String(char c) {
    char str[] = {c, '\0'};
    createString(str);
}

String::String(int val) {

    // Number of char needed to represent the integer in a string + '\0'
    size_t length = snprintf(nullptr, 0, "%d", val) + 1;

    char *str = new char[length];

    snprintf(str, length, "%d", val);

    createString(str);

    delete[] str;
}

String::String(double val) {

    // Number of char needed to represent the double in a string + '\0'
    size_t length = snprintf(nullptr, 0, "%g", val) + 1;

    char str[length];

    snprintf(str, length, "%g", val);

    createString(str);
}

String::String(bool val) {
    createString(val ? "true" : "false");
}

void String::createString(const char *str) {

    value = new char[strlen(str) + 1];
    strcpy(value, str);
}

size_t String::length() const {
    return strlen(value);
}

void String::print() {
    cout << *this << endl;
}

const char *String::getValue() {
    return value;
}

char &String::charAt(size_t index) {

    if (index >= strlen(value)) {
        throw std::out_of_range("Out of range");
    }

    return value[index];
}

const char &String::charAt(size_t index) const {
    return charAt(index);
}

bool String::equals(const char *c) const {
    return strcmp(this->value, c) == 0;
}

bool String::equals(const String &str) const {
    return this->equals(str.value);
}

String &String::setValue(const char *c) {
    if (*this == c) {
        return *this;
    }

    delete[] value;
    createString(c);
    return *this;
}

String &String::setValue(const String &str) {
    this->setValue(str.value);
    return *this;
}

String &String::append(const char *c) {

    String tmp(*this);

    delete[] value;
    value = new char[strlen(tmp.value) + strlen(c)];

    strcpy(value, tmp.value);
    strcat(value, c);

    return *this;
}

String &String::append(const String &str) {
    this->append(str.value);

    return *this;
}

String String::concat(const String &str) const {
    return *this + str;
}

String String::concat(const char *c) const {
    return *this + c;
}

String String::subString(const size_t &start, const size_t &end) const {

    if (start >= length() || end > length()) {
        throw std::out_of_range("Out of range");
    }

    if (start >= end) {
        throw std::invalid_argument("Invalid argument: start must be lower than end.");
    }

    size_t length = end - start;
    char *tmp = new char[length + 1];
    strncpy(tmp, value + start, length);
    tmp[length] = '\0';

    String tmp2(tmp);
    delete[] tmp;
    return tmp2;
}

void String::read() {
    cin >> *this;
}

String &String::operator+=(const char *c) {
    this->append(c);
    return *this;
}

String &String::operator+=(const String &str) {
    this->append(str);
    return (*this);
}

String operator+(const String &str, const char *c) {
    String tmp(str);
    return tmp += c;
}

String operator+(const char *c, const String &str) {
    String tmp(c);
    return tmp + str;
}


String operator+(const String &str1, const String &str2) {
    String tmp(str1);
    return tmp += str2;
}

ostream &operator<<(ostream &out, const String &str) {
    out << str.value;
    return out;
}

istream &operator>>(istream &in, String &str) {

    delete[] str.value;
    str.createString("");

    char c;
    int index = 0;
    const int BUFFER_SIZE = 100;
    char buffer[BUFFER_SIZE + 1]; // + 1 for '\0'

    bool canRead = false;
    do {

        in.get(c);
        canRead = (c != '\n' && in.good());

        // add char to buffer
        if (canRead) {
            buffer[index] = c;
            index++;
        }

        // append buffer to string at line end or when buffer is full
        if (!canRead || index == BUFFER_SIZE) {
            buffer[index] = '\0';
            index = 0;

            str.append(buffer);
        }

    } while (canRead);

    return in;
}

char &String::operator[](size_t index) {
    return this->charAt(index);
}

const char &String::operator[](size_t index) const {
    return this->charAt(index);
}

bool operator==(const String &str, const char *c) {
    return str.equals(c);
}

bool operator==(const char *c, const String &str) {
    return str.equals(c);
}

bool operator==(const String &str1, const String &str2) {
    return str1.equals(str2);
}

bool operator!=(const String &str, const char *c) {
    return !(str == c);
}

bool operator!=(const char *c, const String &str) {
    return (str != c);
}

bool operator!=(const String &str1, const String &str2) {
    return !(str1 == str2);
}


String &String::operator=(const char *c) {

    if (*this == c) {
        return *this;
    }

    return setValue(c);
}

String &String::operator=(const String &str) {

    return *this = str.value;
}

String::~String() {

    if (value != nullptr) {
        delete[] value;
        value = nullptr;
    }
}
