/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Object
{
public:

    Object(int x) : x(x){}

    operator bool() const { cout << "operator bool() const\n"; return x; }
    operator char() const { cout << "operator char() const\n"; return x; }
    explicit operator float() const { cout << "operator float() const\n"; return x; }

    int x;    
};

int main()
{
    Object o(44);
    
    bool a = o;
    char c = o;
    //float f = o; // error - conversion from ‘Object’ to ‘float’ is ambiguous
    float f = static_cast<float>(o); // OK - explicit cast required

    return 0;
}

/*
RESULT:

operator bool() const
operator char() const
operator float() const
*/
