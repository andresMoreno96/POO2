/* 
 * File:   main.cpp
 * Author: Andres Moreno , Simon Walther
 *
 * Created on March 7, 2019, 2:37 PM
 */

#include <cstdlib>
#include <iostream>
#include <sstream>

#include <string>
#include "cstring.hpp"

using namespace std;

/*
 * Tests the class String the we created.
 */
int main() {
    
    cout << "Test constructors:" << endl << endl;
    
    String s("Hello");
    cout << "Default constructor: " << String() << endl;
    cout << "Copy c string \"Hello\": " << s << endl;
    cout << "Copy String: " << String(s) << endl;
    cout << "From char 'a': " << String('a') << endl;
    cout << "From integer -127: " << String(-127) << endl;
    cout << "From double -12.568: " << String(-12.568) << endl;
    cout << "From Boolean true: " << String(true) << endl;
    
    cout << endl << "Test functions:" << endl << endl;
    
    cout << "Lenght of \"Hello\": " << s.length() << endl;
    
    cout << "Get value: ";
    const char* c = s.getValue();
    for (size_t i = 0; i < strlen(c); ++i) {
        cout << c[i];
    }
    cout << endl;
    
    for (size_t i = 0; i <= s.length(); ++i) {
        try {
            cout << "Char at " << i << ": " << s.charAt(i);
        } catch (const out_of_range& error) {
            cout << "Error: " << error.what();
        }
        cout << endl;
    }
    
    cout << endl << "Equals c string \"Hello\": " << s.equals("Hello") << endl;
    cout << "Equals String(\"Hello\"): " << s.equals(String("Hello")) << endl;
    cout << "Equals String(\"hellO\"): " << s.equals(String("hellO")) << endl;
    
    s.setValue("Bonjour");
    cout << endl << "Set value to c string \"Bonjour\": " << s << endl;
    s.setValue(String("Hello"));
    cout << "Set value to String(\"Hello\"): " << s << endl;
    
    s.append(", Wo");
    cout << endl << "Append c string \", Wo\": " << s << endl;
    s.append(String("rld!"));
    cout << "Append String(\"rld!\"): " << s << endl;
    
    cout << endl << "Sub-string to get \"World\": " << s.subString(7, 12) << endl;
    cout << "Start out of range sub-string: ";
    try {
        cout << s.subString(10, 20) << endl;
    } catch (const out_of_range& error) {
        cout << "Error: " << error.what() << endl;
    }
    
    cout << "End out of range sub-string: ";
    try {
        cout << s.subString(20, 10) << endl;
    } catch (const out_of_range& error) {
        cout << "Error: " << error.what() << endl;
    }
    
    cout << "Invalid arguments sub-string: ";
    try {
        cout << s.subString(10, 5) << endl;
    } catch (const invalid_argument& error) {
        cout << "Error: " << error.what() << endl;
    }
    
    cout << endl << "Print: ";
    s.print();
    
    String s2;
    cout << endl << "Read -> Enter a string: ";
    s2.read();
    cout << "You typed: " << s2 << endl;
    
    cout << endl << "Test operator overloads:" << endl << endl;
    
    cout << "Print with <<: " << s << endl;
    
    stringstream ss("Hello");
    cout << "Read from string stream containing \"Hello\" with >>: ";
    ss >> s;
    cout << s << endl;
    
    String s3 = String("Hel") + "lo";
    cout << endl << "String(\"Hel\") + \"lo\": " << s3 << endl;
    cout << "String += \", World!\": " << (s3 += ", World!") << endl;
    
    String s4 = String("Hel") + String("lo");
    cout << endl << "String(\"Hel\") + String(\"lo\"): " << s4 << endl;
    cout << "String += String(\", World!\"): " << (s4 += String(", World!")) << endl << endl;
    
    for (size_t i = 0; i <= s.length(); ++i) {
        try {
            cout << "Char at [" << i << "]: " << s[i];
        } catch (const out_of_range& error) {
            cout << "Error: " << error.what();
        }
        cout << endl;
    }
    
    cout << endl << "String == \"Hello\": " << (s == "Hello") << endl;
    cout << "String != \"Hello\": " << (s != "Hello") << endl;
    cout << "String == String(\"Hello\"): " << (s == String("Hello")) << endl;
    cout << "String != String(\"Hello\"): " << (s != String("Hello")) << endl;
    
    String s5;
    s5 = String("Hello");
    cout << endl << "String = String(\"Hello\"): " << s << endl;
    
    return EXIT_SUCCESS;
}

