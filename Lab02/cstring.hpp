/* 
 * File:   String.hpp
 * Author: Andres Moreno , Simon Walther
 *
 * Created on March 7, 2019, 2:44 PM
 */

#ifndef STRING_H
#define	STRING_H
#include <string.h>
#include <iostream>

class String {
public:
    /**
     * @brief overload the << operator
     */
    friend std::ostream& operator<<(std::ostream & out, const String & str);

    /**
     * @brief overload the >> operator
     */
    friend std::istream& operator>>(std::istream & in, String & str);

    /**
     * 
     * @brief Constructor of an empty String
     */
    String();

    /**
     * @brief Constructor of a String from a string of characters.
     * @param str string that will be copied
     */
    explicit String(const char* str);

    /**
     * @brief Constructor of copy
     * @param str the String to copy
     */
    String(const String& str);

    /**
     * @brief Constructor of a String from a given char
     * @param c the char
     */
    explicit String(char c);

    /**
     * @brief Constructor of a String from a given int
     * @param val integer
     */
    explicit String(int val);

    /**
     * @brief Constructor of a String from a given double
     * @param val double
     */
    explicit String(double val);

    /**
     * @brief Constructor of a String from a boolean
     * @param val boolean
     */
    explicit String(bool val);

    /**
     * 
     * @return the length of the String
     */
    size_t length() const;

    /**
     * 
     * @return the value of the String
     */
    char* getValue() const;

    /**
     * 
     * @param index the position
     * @return a reference to the character at position index in the String.
     * @throws out_of_range if the index is higher than the length of the String.
     */
    char& charAt(size_t index);

    /**
     * 
     * @param c character string to compare
     * @return true if characters strings are equal otherwise false.
     */
    bool equals(const char* c) const;

    /**
     * 
     * @param str String to compare
     * @return true if both Strings are equal otherwise false.
     */
    bool equals(const String& str)const;

    /**
     * @breif sets the given value to the String
     * @param c the value we would like to set
     */
    void setValue(const char* c);

    /**
     * @breif sets the given value to the String
     * @param str the new String value
     */
    void setValue(const String& str);

    /**
     * @brief Appends a copy of a character string
     * @param c the character string
     */
    void append(const char* c);

    /**
     * @brief Appends a copy of a String
     * @param str the String that will be appended
     */
    void append(const String& str);

    /**
     * @brief extraction of a substring between two given indices [start;end).
     * @param start the first index (included)
     * @param end the last index (excluded)
     * @return the String between the two given indices.
     * @throws out_of_range if start or end are higher than the length 
     * @throws invalid_argument if start is higher than the end
     */
    String subString(const size_t& start, const size_t& end);

    /**
     * @brief prints a String
     */
    void print();

    /**
     * @brief keyboard reading of a word and a line containing spaces.
     */
    void read();

    /**
     * @brief overload the += operator
     * @param c the character string to add
     * @return a new instance of the String
     */
    String& operator+=(const char* c);

    /**
     * @brief overload the + operator
     * @param c the character string to add
     * @return a new instance of the String
     */
    String operator+(const char* c);

    /**
     * @brief overload the += operator
     * @param str the String to add
     * @return a new instance of the String
     */
    String& operator+=(const String& str);

    /**
     * @brief overload the + operator
     * @param str the String to add
     * @return a new instance of the String
     */
    String operator+(const String& str);

    /**
     * @brief overload the [] operator
     * @param index the position
     * @return reference to the character at position index in the String.
     * 
     * @throws out_of_range if the index higher than the length of the String
     */
    char& operator[](size_t index);

    /**
     * @brief overload the == operator
     * @param c character string to be compared
     * @return true if both characters strings are equal otherwise false
     */
    bool operator==(const char* c) const;
    
    /**
     * @brief overload the == operator
     * @param str the String to be compared
     * @return true if both Strings are equal otherwise false
     */
    bool operator==(const String& str) const;
    
    /**
     * @brief overload the != operator
     * @param c character string to be compared
     * @return true if both characters strings are different otherwise false
     */
    bool operator!=(const char* c) const;
    
    /**
     * @brief overload the != operator
     * @param str the String to be compared
     * @return true if both characters strings are different otherwise false
     */
    bool operator!=(const String& str) const;
    
    String& operator=(const String& str);

    /**
     * @brief destructor
     */
    virtual ~String();



private:

    char* value;

    /**
     * @breif Creates a String
     * @param str character string
     */
    void createString(const char* str);
};

#endif	/* STRING_H */

