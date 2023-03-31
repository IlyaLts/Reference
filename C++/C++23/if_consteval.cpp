#include <iostream>

constexpr int square(int x)
{
    if consteval
    {
        // Runs only during compile-time evaluation
        return x * x;
    }
    else
    {
        // Runs only at runtime
        std::cout << "Runtime calculation\n";
        return x * x;
    }
}

int main()
{
    constexpr int a = square(5); // compile time
    int b = square(5);           // runtime

    std::cout << a << '\n';
    std::cout << b << '\n';
}