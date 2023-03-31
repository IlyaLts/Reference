/*
==================
The problem

 A
/ \
B C
\ /
 D
==================
*/

#include <iostream>

class A {
    public:
     int x = 5;
     //some other things
};
class B : virtual public A { // inherit from the Class A.
    public:
      int i = 6;
};
class C : virtual public A { // inherit from the Class A.
    public:
      int i = 7;
};
class D : public B, public C { // inherit from both class B and C
    // something can go here..
};

int main(){
    D obj;
    std::cout << obj.x << std::endl;
    return 0;
}

// Output: 5

/*
==================
The problem

A A
| |
B C
\ /
 D
==================
*/

#include <iostream>

class A {
    public:
     int x = 5;
     //some other things
};
class B : public A { // inherit from the Class A.
    public:
      int i = 6;
};
class C : public A { // inherit from the Class A.
    public:
      int i = 7;
};
class D : public B, public C { // inherit from both class B and C
    // something can go here..
};

int main(){
    D obj;
    std::cout << obj.x << std::endl; // error
	
    std::cout << obj.B::x << std::endl; // OK
    std::cout << obj.C::x << std::endl; // OK
	
    return 0;
}

/*
main.cpp: In function ‘int main()’:
main.cpp:22:22: error: request for member ‘x’ is ambiguous
   22 |     std::cout << obj.x << std::endl;
      |                      ^
main.cpp:5:10: note: candidates are: ‘int A::x’
    5 |      int x = 5;
      |          ^
main.cpp:5:10: note:                 ‘int A::x’
*/