#include <iostream>

int main()
{
    //C++ Uses PEMDAS rule for inline arithmetic
    double a{1};
    double b{2};
    double c{3};
    double d{4};
    double e{5};
    double result{a + b * c - e / d};
    std::cout << "result : " << result << std::endl;

    result = (a + b) * c - e / d; //Parenthesis done first
    std::cout << "result : " << result << std::endl;

    //You can lookup "C++ Operator Precedence" Precedence: which operation is done first. Associativity: left to right or right to left

    return 0;
}