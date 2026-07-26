// #include <iostream>
// #include "../include/MyString.h"

// int main()
// {
//     MyString s("Hello World");

//     std::cout << s << std::endl;

//     return 0;
// }

// #include <iostream>
// #include "../include/MyString.h"

// using namespace std;

// int main() {
//     MyString s1("Hello");
//     MyString s2(" World");

//     cout << "s1: " << s1 << endl;
//     cout << "s2: " << s2 << endl;

//     MyString s3 = s1 + s2;
//     cout << "Concatenation: " << s3 << endl;

//     s1.append(s2);
//     cout << "Append: " << s1 << endl;

//     cout << "Length: " << s1.length() << endl;

//     cout << "Substring: " << s1.substr(0, 5) << endl;

//     cout << "Find 'World': " << s1.find(MyString("World")) << endl;

//     s1.reverse();
//     cout << "Reverse: " << s1 << endl;

//     s1.toUpper();
//     cout << "Upper: " << s1 << endl;

//     s1.toLower();
//     cout << "Lower: " << s1 << endl;

//     return 0;
// }

#include <iostream>
#include "../include/MyString.h"

using namespace std;

int main()
{
    cout << "========== CONSTRUCTORS ==========\n";

    MyString s1("Hello");
    MyString s2(" World");
    MyString s3(s1);          // Copy Constructor
    MyString s4 = s2;         // Copy Constructor

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;

    cout << "\n========== CONCATENATION ==========\n";

    MyString s5 = s1 + s2;
    cout << "s1 + s2 = " << s5 << endl;

    s1 += s2;
    cout << "s1 += s2 -> " << s1 << endl;

    cout << "\n========== APPEND ==========\n";

    MyString app("Programming");
    app.append(MyString(" Language"));
    cout << app << endl;

    cout << "\n========== INSERT ==========\n";

    MyString ins("Hello");
    ins.insert(5, MyString(" C++"));
    cout << ins << endl;

    cout << "\n========== ERASE ==========\n";

    ins.erase(5, 4);
    cout << ins << endl;

    cout << "\n========== REPLACE ==========\n";

    MyString rep("I love Java");
    rep.replace(7, 4, MyString("C++"));
    cout << rep << endl;

    cout << "\n========== SUBSTRING ==========\n";

    MyString sub = rep.substr(2, 8);
    cout << sub << endl;

    cout << "\n========== FIND ==========\n";

    MyString text("Data Structures and Algorithms");
    cout << "Algorithms found at index : "
         << text.find(MyString("Algorithms")) << endl;

    cout << "\n========== COMPARE ==========\n";

    MyString a("Apple");
    MyString b("Apple");
    MyString c("Banana");

    cout << "a == b : " << (a == b) << endl;
    cout << "a != c : " << (a != c) << endl;
    cout << "a < c  : " << (a < c) << endl;
    cout << "c > a  : " << (c > a) << endl;
    cout << "compare(a,b) : " << a.compare(b) << endl;
    cout << "compare(a,c) : " << a.compare(c) << endl;

    cout << "\n========== REVERSE ==========\n";

    MyString rev("Programming");
    rev.reverse();
    cout << rev << endl;

    cout << "\n========== UPPER ==========\n";

    rev.toUpper();
    cout << rev << endl;

    cout << "\n========== LOWER ==========\n";

    rev.toLower();
    cout << rev << endl;

    cout << "\n========== SWAP ==========\n";

    MyString x("ABC");
    MyString y("XYZ");

    cout << "Before Swap\n";
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    x.swap(y);

    cout << "After Swap\n";
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    cout << "\n========== INDEXING ==========\n";

    MyString idx("Computer");
    cout << "Original : " << idx << endl;

    idx[0] = 'c';
    cout << "Modified : " << idx << endl;

    cout << "Character at index 3 : " << idx.at(3) << endl;

    cout << "\n========== LENGTH & EMPTY ==========\n";

    cout << "Length : " << idx.length() << endl;
    cout << "Empty : " << idx.empty() << endl;

    idx.clear();

    cout << "After clear()\n";
    cout << "Length : " << idx.length() << endl;
    cout << "Empty : " << idx.empty() << endl;

    cout << "\n========== COPY ASSIGNMENT ==========\n";

    MyString copy1("First");
    MyString copy2("Second");

    copy2 = copy1;

    cout << "copy1 = " << copy1 << endl;
    cout << "copy2 = " << copy2 << endl;

    cout << "\n========== MOVE CONSTRUCTOR ==========\n";

    MyString move1("Temporary");
    MyString move2(std::move(move1));

    cout << "move2 = " << move2 << endl;

    cout << "\n========== EXCEPTION TEST ==========\n";

    try
    {
        MyString test("ABC");
        cout << test.at(10) << endl;
    }
    catch (const exception &e)
    {
        cout << "Exception Caught : " << e.what() << endl;
    }

    cout << "\n========== ALL TESTS COMPLETED ==========\n";

    return 0;
}