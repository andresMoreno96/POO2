/* 
 * File:   main.cpp
 * Author: Andres Moreno , Simon Walther
 *
 * Created on March 7, 2020, 2:37 PM
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
    cout << "From Boolean false: " << String(false) << endl;
    
    cout << endl << "Test functions:" << endl << endl;
    
    cout << "Length of \"Hello\": " << s.length() << endl;
    
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

    cout << endl;

    for (size_t i = 0; i <= s.length(); ++i) {
        try {
            const char& c2 = s.charAt(i);
            cout << "Constant char at: " << i << ": " << c2;
        } catch (const out_of_range& error) {
            cout << "Error: " << error.what();
        }
        cout << endl;
    }

    cout << endl << "Equals c string \"Hello\": " << (s.equals("Hello") ? "true" : "false") << endl;
    cout << "Equals String(\"Hello\"): " << (s.equals(String("Hello")) ? "true" : "false") << endl;
    cout << "Equals String(\"hellO\"): " << (s.equals(String("hellO")) ? "true" : "false") << endl;

    s.setValue("Bonjour");
    cout << endl << "Set value to c string \"Bonjour\": " << s << endl;
    s.setValue(String("Hello"));
    cout << "Set value to String(\"Hello\"): " << s << endl;
    
    s.append(", Wo");
    cout << endl << "Append c string \", Wo\": " << s << endl;
    s.append(String("rld!"));
    cout << "Append String(\"rld!\"): " << s << endl;

    String tmp("Hello");
    String tmp2(", World");

    cout << endl << "Concat String(\"Hello\") with c string \", World\": " << tmp.concat(", World") << endl;
    cout << "Concat String(\"Hello\") with String(\", World\"): " << tmp.concat(tmp2) << endl;

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

    String s3b = "Hel" + String("lo");
    cout << endl << "\"Hel\" + String(\"lo\"): " << s3b << endl;

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

    cout << endl;

    String s5;
    s5 = String("Hello");
    char& c3 = s5[0];
    c3 = 'h';
    cout << "c3 = char at [0]: " << c3 << endl;
    cout << "c3 = 'h', s: " << s5 << endl;

    const char& c4 = s[0];
    cout << endl << "string s: String(\"Hello\")" << endl;
    cout << "const char& c4 = s[0]: " << c4 << endl;
    
    cout << endl << "String == \"Hello\": " << ((s == "Hello") ? "true" : "false") << endl;
    cout << "String != \"Hello\": " << ((s != "Hello") ? "true" : "false") << endl;
    cout << "String == String(\"Hello\"): " << ((s == String("Hello")) ? "true" : "false") << endl;
    cout << "String != String(\"Hello\"): " << ((s != String("Hello")) ? "true" : "false") << endl;

    String s6;
    s6 = String("Hello");
    cout << endl << "String = String(\"Hello\"): " << s << endl;

    return EXIT_SUCCESS;
}

