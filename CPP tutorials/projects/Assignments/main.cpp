#include <iostream>

int main()
{
    int var1{123}; //Declare and initialize
    std::cout << "var1 : " << var1 << std::endl;

    var1 = 55; //Assignment
    std::cout << "var1 : " << var1 << std::endl;

    std::cout << "------------------" << std::endl;
    
    double var2{99.99}; //Declare and initialize
    std::cout << "var2 : " << var2 << std::endl;

    var2 = 28.22; //Assignment
    std::cout << "var2 : " << var2 << std::endl;

    std::cout << "------------------" << std::endl;

    bool state{true}; //Declare and initialize
    std::cout << std::boolalpha;
    std::cout << "state : " << state << std::endl;

    state = false; //Assignment
    std::cout << "state : " << state << std::endl;

    std::cout << "------------------" << std::endl;

    //Auto type dedection
    auto var3{333u}; //Declare and initialize with type deduction (unsigned int)
    std::cout << "var3 : " << var3 << std::endl;

    var3 = -22; //Assignment of negative number. Runtime error! Will output garbage value
    std::cout << "var3 : " << var3 << std::endl;
    return 0;
}