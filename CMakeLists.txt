# ==============================================================================
# MyString - Custom String Class in C++
#
# Author      : Jyatin Singh
# Language    : C++17
# Build System: CMake
# Version     : 1.0.0
#
# Description:
#   A custom implementation of a std::string-like class built from scratch.
#   This project demonstrates:
#       • Rule of Five
#       • Dynamic Memory Management
#       • Move Semantics
#       • Operator Overloading
#       • Exception Handling
#       • Object-Oriented Programming
# ==============================================================================

cmake_minimum_required(VERSION 3.10)

# ==============================================================================
# Project Information
# ==============================================================================

project(
    MyStringProject
    VERSION 1.0.0
    DESCRIPTION "Custom String Class implemented in Modern C++"
    LANGUAGES CXX
)

# ==============================================================================
# C++ Standard
# ==============================================================================

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ==============================================================================
# Build Type
# ==============================================================================

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# ==============================================================================
# Include Directories
# ==============================================================================

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

# ==============================================================================
# Source Files
# ==============================================================================

set(SOURCE_FILES
    src/MyString.cpp
)

set(TEST_FILES
    tests/main.cpp
)

# ==============================================================================
# Executable
# ==============================================================================

add_executable(
    CustomString
    ${SOURCE_FILES}
    ${TEST_FILES}
)

# ==============================================================================
# Compiler Warnings
# ==============================================================================

if(MSVC)

    target_compile_options(CustomString PRIVATE
        /W4
    )

else()

    target_compile_options(CustomString PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wshadow
        -Wconversion
    )

endif()

# ==============================================================================
# Output Directory
# ==============================================================================

set_target_properties(CustomString PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/bin
)

# ==============================================================================
# Installation
# ==============================================================================

install(
    TARGETS CustomString
    RUNTIME DESTINATION bin
)

# ==============================================================================
# Build Summary
# ==============================================================================

message(STATUS "")
message(STATUS "==============================================")
message(STATUS "Project Name     : ${PROJECT_NAME}")
message(STATUS "Version          : ${PROJECT_VERSION}")
message(STATUS "Compiler         : ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ Standard     : C++${CMAKE_CXX_STANDARD}")
message(STATUS "Build Type       : ${CMAKE_BUILD_TYPE}")
message(STATUS "Binary Directory : ${PROJECT_BINARY_DIR}")
message(STATUS "==============================================")
message(STATUS "")