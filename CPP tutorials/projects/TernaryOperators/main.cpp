#include <iostream>

int main()
{
    int max{};
    int a{55};
    int b{40};

    //Regular if statement
    std::cout << "Regular if statement" << std::endl;
    if (a > b)
    {
        max = a;
    }
    else
    {
        max = b;
    }
    std::cout << "max : " << max << std::endl;

    //Ternary operator
    max = (a > b) ? a : b ; //Note: result1 and result2 must be of the same type (e.g., a : b instead of a : "b")
    //Note: result1 and result2 can be of different type, but they must be convertible (e.g., int and float)
    std::cout << "max : " << max << std::endl;

    //Ternary initialization
    std::cout << std::endl;
    std::cout << "speed" << std::endl;
    bool fast{true};

    int speed{ fast ? 300 : 150}; //initializes speed to be 300 if fast=true, or 150 if fast=false.

    std::cout << "The speed is " << speed << std::endl;
    return 0;
}