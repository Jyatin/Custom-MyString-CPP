#include "../include/MyString.h"

#include <cstring>
#include <stdexcept>
#include <cctype>
#include <utility>

//=====================================================
// Static Member
//=====================================================

const size_t MyString::npos = static_cast<size_t>(-1);

//=====================================================
// Private Helper Functions
//=====================================================

void MyString::allocateAndCopy(const char* src, size_t len)
{
    data_ = new char[len + 1];

    for (size_t i = 0; i < len; i++)
    {
        data_[i] = src[i];
    }

    data_[len] = '\0';
    length_ = len;
}

void MyString::freeMemory()
{
    delete[] data_;
    data_ = nullptr;
    length_ = 0;
}

void MyString::checkIndex(size_t index) const
{
    if (index >= length_)
    {
        throw std::out_of_range("Index out of range");
    }
}

//=====================================================
// Constructors
//=====================================================

MyString::MyString()
{
    data_ = new char[1];
    data_[0] = '\0';
    length_ = 0;
}

MyString::MyString(const char* cstr)
{
    if (cstr == nullptr)
    {
        throw std::invalid_argument("Null pointer passed");
    }

    allocateAndCopy(cstr, std::strlen(cstr));
}

MyString::MyString(const MyString& other)
{
    allocateAndCopy(other.data_, other.length_);
}

MyString::MyString(MyString&& other) noexcept
{
    data_ = other.data_;
    length_ = other.length_;

    other.data_ = nullptr;
    other.length_ = 0;
}

//=====================================================
// Destructor
//=====================================================

MyString::~MyString()
{
    delete[] data_;
}

//=====================================================
// Assignment Operators
//=====================================================

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        MyString temp(other);
        swap(temp);
    }

    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
    if (this != &other)
    {
        delete[] data_;

        data_ = other.data_;
        length_ = other.length_;

        other.data_ = nullptr;
        other.length_ = 0;
    }

    return *this;
}

//=====================================================
// Capacity Functions
//=====================================================

size_t MyString::length() const
{
    return length_;
}

bool MyString::empty() const
{
    return length_ == 0;
}

void MyString::clear()
{
    delete[] data_;

    data_ = new char[1];
    data_[0] = '\0';

    length_ = 0;
}

//=====================================================
// Element Access
//=====================================================

const char* MyString::c_str() const
{
    return data_;
}

char& MyString::at(size_t index)
{
    checkIndex(index);
    return data_[index];
}

const char& MyString::at(size_t index) const
{
    checkIndex(index);
    return data_[index];
}

char& MyString::operator[](size_t index)
{
    return data_[index];
}

const char& MyString::operator[](size_t index) const
{
    return data_[index];
}

//=====================================================
// String Modification Functions
//=====================================================

MyString& MyString::append(const MyString& other)
{
    size_t newLength = length_ + other.length_;

    char* newData = new char[newLength + 1];

    std::memcpy(newData, data_, length_);
    std::memcpy(newData + length_, other.data_, other.length_);

    newData[newLength] = '\0';

    delete[] data_;

    data_ = newData;
    length_ = newLength;

    return *this;
}

//-----------------------------------------------------

MyString& MyString::insert(size_t pos, const MyString& other)
{
    if (pos > length_)
    {
        throw std::out_of_range("Insert position out of range");
    }

    size_t newLength = length_ + other.length_;

    char* newData = new char[newLength + 1];

    // Copy before insertion point
    std::memcpy(newData,
                data_,
                pos);

    // Copy inserted string
    std::memcpy(newData + pos,
                other.data_,
                other.length_);

    // Copy remaining part
    std::memcpy(newData + pos + other.length_,
                data_ + pos,
                length_ - pos);

    newData[newLength] = '\0';

    delete[] data_;

    data_ = newData;
    length_ = newLength;

    return *this;
}

//-----------------------------------------------------

MyString& MyString::erase(size_t pos, size_t count)
{
    if (pos > length_)
    {
        throw std::out_of_range("Erase position out of range");
    }

    if (pos + count > length_)
    {
        count = length_ - pos;
    }

    size_t newLength = length_ - count;

    char* newData = new char[newLength + 1];

    // Copy characters before erased section
    std::memcpy(newData,
                data_,
                pos);

    // Copy characters after erased section
    std::memcpy(newData + pos,
                data_ + pos + count,
                length_ - pos - count);

    newData[newLength] = '\0';

    delete[] data_;

    data_ = newData;
    length_ = newLength;

    return *this;
}

//-----------------------------------------------------

MyString& MyString::replace(size_t pos,
                            size_t count,
                            const MyString& other)
{
    erase(pos, count);
    insert(pos, other);

    return *this;
}

//=====================================================
// Search Functions
//=====================================================

MyString MyString::substr(size_t pos, size_t count) const
{
    if (pos > length_)
    {
        throw std::out_of_range("Substring position out of range");
    }

    if (pos + count > length_)
    {
        count = length_ - pos;
    }

    char* buffer = new char[count + 1];

    std::memcpy(buffer,
                data_ + pos,
                count);

    buffer[count] = '\0';

    MyString result(buffer);

    delete[] buffer;

    return result;
}

//-----------------------------------------------------

size_t MyString::find(const MyString& other) const
{
    if (other.length_ == 0)
    {
        return 0;
    }

    if (other.length_ > length_)
    {
        return npos;
    }

    for (size_t i = 0; i <= length_ - other.length_; i++)
    {
        bool found = true;

        for (size_t j = 0; j < other.length_; j++)
        {
            if (data_[i + j] != other.data_[j])
            {
                found = false;
                break;
            }
        }

        if (found)
        {
            return i;
        }
    }

    return npos;
}

//-----------------------------------------------------

int MyString::compare(const MyString& other) const
{
    return std::strcmp(data_, other.data_);
}

//=====================================================
// Utility Functions
//=====================================================

void MyString::reverse()
{
    if (length_ <= 1)
    {
        return;
    }

    size_t left = 0;
    size_t right = length_ - 1;

    while (left < right)
    {
        std::swap(data_[left], data_[right]);

        left++;
        right--;
    }
}

//-----------------------------------------------------

void MyString::toUpper()
{
    for (size_t i = 0; i < length_; i++)
    {
        data_[i] = static_cast<char>(
            std::toupper(static_cast<unsigned char>(data_[i])));
    }
}

//-----------------------------------------------------

void MyString::toLower()
{
    for (size_t i = 0; i < length_; i++)
    {
        data_[i] = static_cast<char>(
            std::tolower(static_cast<unsigned char>(data_[i])));
    }
}

//-----------------------------------------------------

void MyString::swap(MyString& other) noexcept
{
    std::swap(data_, other.data_);
    std::swap(length_, other.length_);
}

//=====================================================
// Concatenation Operators
//=====================================================

MyString MyString::operator+(const MyString& other) const
{
    MyString result(*this);

    result.append(other);

    return result;
}

//-----------------------------------------------------

MyString& MyString::operator+=(const MyString& other)
{
    return append(other);
}

//=====================================================
// Comparison Operators
//=====================================================

bool MyString::operator==(const MyString& other) const
{
    return compare(other) == 0;
}

//-----------------------------------------------------

bool MyString::operator!=(const MyString& other) const
{
    return compare(other) != 0;
}

//-----------------------------------------------------

bool MyString::operator<(const MyString& other) const
{
    return compare(other) < 0;
}

//-----------------------------------------------------

bool MyString::operator>(const MyString& other) const
{
    return compare(other) > 0;
}

//-----------------------------------------------------

bool MyString::operator<=(const MyString& other) const
{
    return compare(other) <= 0;
}

//-----------------------------------------------------

bool MyString::operator>=(const MyString& other) const
{
    return compare(other) >= 0;
}

//=====================================================
// Stream Operators
//=====================================================

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
    os << str.data_;
    return os;
}

//-----------------------------------------------------

std::istream& operator>>(std::istream& is, MyString& str)
{
    char buffer[1000];

    is >> buffer;

    MyString temp(buffer);

    str.swap(temp);

    return is;
}