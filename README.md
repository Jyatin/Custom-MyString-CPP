# MyString - Custom String Class in C++

![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![Status](https://img.shields.io/badge/Status-Completed-success)
![License](https://img.shields.io/badge/License-MIT-green)

## Overview

**MyString** is a custom implementation of a string class built entirely in **C++17** without using `std::string` for internal storage.

The project demonstrates how dynamic memory allocation, object-oriented programming, copy/move semantics, and operator overloading work behind the scenes in a string implementation similar to `std::string`.

This project was developed for learning modern C++ concepts and strengthening understanding of memory management and class design.

---

# Features

- Dynamic memory allocation using `new[]` and `delete[]`
- Rule of Five implementation
- Copy Constructor
- Move Constructor
- Copy Assignment Operator
- Move Assignment Operator
- Destructor
- String Concatenation
- Append
- Insert
- Erase
- Replace
- Substring Extraction
- String Search
- Lexicographical Comparison
- Reverse String
- Uppercase Conversion
- Lowercase Conversion
- Swap
- Bounds Checking
- Stream Input/Output Operators
- Exception Handling

---

# Concepts Demonstrated

This project demonstrates the following C++ concepts:

- Object-Oriented Programming (OOP)
- Encapsulation
- Constructors & Destructors
- Dynamic Memory Management
- Deep Copy vs Shallow Copy
- Move Semantics
- Rule of Five
- Operator Overloading
- Exception Handling
- Const Correctness
- Pointer Manipulation
- Custom Data Structures

---

# Project Structure

```
cpp project/
│
├── include/
│   └── MyString.h
│
├── src/
│   └── MyString.cpp
│
├── tests/
│   └── main.cpp
│
├── CMakeLists.txt
│
└── README.md
```

---

# Public Member Functions

| Function | Description |
|----------|-------------|
| length() | Returns string length |
| empty() | Checks if string is empty |
| clear() | Clears the string |
| append() | Appends another string |
| insert() | Inserts a string at a position |
| erase() | Removes characters |
| replace() | Replaces a substring |
| substr() | Returns a substring |
| find() | Searches for a substring |
| compare() | Lexicographical comparison |
| reverse() | Reverses the string |
| toUpper() | Converts to uppercase |
| toLower() | Converts to lowercase |
| swap() | Swaps two strings |
| c_str() | Returns C-style string |

---

# Operator Overloading

Implemented operators:

```cpp
+
+=
==
!=
<
>
<=
>=
[]
<<
>>
```

---

# Build Instructions

## Using g++

```bash
g++ tests/main.cpp src/MyString.cpp -Iinclude -std=c++17 -o CustomString
```

Run:

### Windows

```powershell
.\CustomString.exe
```

### Linux / macOS

```bash
./CustomString
```

---

# Build Using CMake

```bash
mkdir build
cd build

cmake ..
cmake --build .
```

Run:

```bash
./CustomString
```

---

# Sample Output

```text
========== CONSTRUCTORS ==========
s1 = Hello
s2 = World

========== CONCATENATION ==========
Hello World

========== APPEND ==========
Programming Language

========== INSERT ==========
Hello C++

========== REPLACE ==========
I love C++

========== REVERSE ==========
gnimmargorP

========== UPPER ==========
GNIMMARGORP

========== LOWER ==========
gnimmargorp

========== ALL TESTS COMPLETED ==========
```

---

# Testing

The project includes tests for:

- Constructors
- Copy Semantics
- Move Semantics
- Concatenation
- Append
- Insert
- Erase
- Replace
- Substring
- Find
- Compare
- Reverse
- Case Conversion
- Swap
- Indexing
- Bounds Checking
- Exception Handling

All tests pass successfully.

---

# Learning Outcomes

Through this project, the following concepts were explored:

- Manual memory management
- Designing reusable C++ classes
- Implementing copy and move semantics
- Writing exception-safe code
- Building custom string manipulation algorithms
- Understanding the internals of `std::string`

---

# Future Improvements

Possible enhancements include:

- Small String Optimization (SSO)
- Iterator support
- Capacity management
- Reserve and resize functions
- UTF-8 support
- Custom allocators
- Additional STL-compatible interfaces

---

# Technologies Used

- C++17
- GCC / MinGW
- Visual Studio Code
- CMake

---

# Author

**Jyatin Singh**

B.Tech Computer Science & Engineering

---

# License

This project is released under the MIT License.