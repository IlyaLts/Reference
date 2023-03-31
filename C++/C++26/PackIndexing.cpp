#include <iostream>

template<typename... Args> void print_second(Args... args)
{
    std::cout << args...[1] << '\n';
}

int main()
{
    print_second(10, 20, 30);
}

////////////////////////////////////////////////////////////

template<typename... Args> void print_last(Args... args)
{
    std::cout << args...[sizeof...(Args) - 1] << '\n';
}