/* 
 * File:   String.cpp
 * Author: Andres Moreno , Simon Walther
 * 
 * Created on March 7, 2019, 2:44 PM
 */

#include "cstring.hpp"
#include <iostream>
#include <stdio.h>



using namespace std;

String::String() {
    createString("");
}

String::String(const char* str) {
    createString(str);
}

String::String(const String& str) : String(str.value) {}

String::String(char c) {
    char str[] = {c, '\0'};
    createString(str);
}

String::String(int val) {

    // Number of char needed to represent the integer in a string + '\0'
    size_t length = snprintf(nullptr, 0, "%d", val) + 1;

    char str[length];

    snprintf(str, length, "%d", val);

    createString(str);
}

String::String(double val) {

    // Number of char needed to represent the double in a string + '\0'
    size_t length = snprintf(nullptr, 0, "%f", val) + 1;

    char str[length];

    snprintf(str, length, "%f", val);

    createString(str);
}

String::String(bool val) {
    createString(val ? "true" : "false");
}

void String::createString(const char* str) {

    value = new char[strlen(str) + 1];
    strcpy(value, str);
}

size_t String::length()const {
    return strlen(value);
}

void String::print() {
    cout << *this << endl;
}

char* String::getValue()const {
    return value;
}

char& String::charAt(size_t index) {

    if (index >= strlen(value)) {
        throw std::out_of_range("Out of range");
    }
    
    return value[index];
}

bool String::equals(const char* c) const {
    return strcmp(this->value, c) == 0;
}

bool String::equals(const String& str) const {
    return this->equals(str.value);
}

void String::setValue(const char* c) {
    delete[] value;
    createString(c);
}

void String::setValue(const String& str) {
    this->setValue(str.value);
}

void String::append(const char* c) {

    String tmp(*this);

    delete[] value;
    value = new char [strlen(tmp.value) + strlen(c)];

    strcpy(value, tmp.value);
    strcat(value, c);
}

void String::append(const String& str) {
    this->append(str.value);
}

String String::subString(const size_t& start, const size_t& end) {

    if (start >= length() || end > length()) {
        throw std::out_of_range("Out of range");
    }
    
    if (start >= end) {
        throw std::invalid_argument("Invalid argument: start must be lower than end.");
    }
    
    size_t length = end - start;
    char tmp[length + 1];
    strncpy(tmp, value + start, length);

    return String(tmp);
}

void String::read() {
    cin >> *this;
}

String& String::operator+=(const char* c) {
    this->append(c);
    return *this;
}

String String::operator+(const char* c) {
    String tmp(*this);
    return tmp += c;
}

String& String::operator+=(const String& str) {
    this->append(str);
    return (*this);
}

String String::operator+(const String& str) {
    String tmp(*this);
    return tmp += str;
}

ostream & operator<<(ostream & out, const String & str) {
    out << str.value;
    return out;
}

istream & operator>>(istream & in, String & str) {

    delete [] str.value;
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

char& String::operator[](size_t index) {
    return this->charAt(index);
}

bool String::operator==(const char* c)const {
    return this->equals(c);
}

bool String::operator==(const String& str)const {
    return this->equals(str);
}

bool String::operator!=(const char* c)const {
    return !(*this == c);
}

bool String::operator!=(const String& str)const {
    return !(*this == str);
}

String& String::operator=(const String& str) {
    createString(str.value);
    return *this;
}

String::~String() {
    
    if (value != nullptr) {
        delete [] value;
        value = nullptr;
    }
}
