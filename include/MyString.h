#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstddef>
#include <iostream>

class MyString {
public:
    // Constant representing "not found"
    static const size_t npos;

    // Constructors & Destructor (Rule of Five)
    MyString();
    MyString(const char* cstr);
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;
    ~MyString();

    // Assignment Operators
    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;

    // Capacity
    size_t length() const;
    bool empty() const;
    void clear();

    // Access
    const char* c_str() const;
    char& at(size_t index);
    const char& at(size_t index) const;

    char& operator[](size_t index);
    const char& operator[](size_t index) const;

    // Modifiers
    MyString& append(const MyString& other);
    MyString& insert(size_t pos, const MyString& other);
    MyString& erase(size_t pos, size_t count);
    MyString& replace(size_t pos, size_t count, const MyString& other);

    void reverse();
    void toUpper();
    void toLower();
    void swap(MyString& other) noexcept;

    // Search
    MyString substr(size_t pos, size_t count) const;
    size_t find(const MyString& other) const;
    int compare(const MyString& other) const;

    // Operators
    MyString operator+(const MyString& other) const;
    MyString& operator+=(const MyString& other);

    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    bool operator<(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>=(const MyString& other) const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);

private:
    char* data_;
    size_t length_;

    // Helper Functions
    void allocateAndCopy(const char* src, size_t len);
    void freeMemory();
    void checkIndex(size_t index) const;
};

#endif