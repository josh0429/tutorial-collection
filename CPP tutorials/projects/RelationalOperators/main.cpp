#include <iostream>

int main()
{
    int number1{45};
    int number2{60};

    std::cout << "number1 : " << number1 << std::endl;
    std::cout << "number2 : " << number2 << std::endl;
    std::cout << std::endl;

    std::cout << "Comparing variables" << std::endl;

    std::cout << std::boolalpha;

    //Note: Need parentheses here due to operator precedence reasons between << and <, etc.
    std::cout << " number1 < number2 : " << (number1 < number2) << std::endl; //true
    std::cout << " number1 <= number2 : " << (number1 <= number2) << std::endl; //true
    std::cout << " number1 > number2 : " << (number1 > number2) << std::endl; //false
    std::cout << " number1 >= number2 : " << (number1 >= number2) << std::endl; //false
    std::cout << " number1 == number2 : " << (number1 == number2) << std::endl; //false
    std::cout << " number1 != number2 : " << (number1 != number2) << std::endl; //true
    std::cout << std::endl;

    std::cout << "Comparing variables (noboolalpha)" << std::endl;
    std::cout << std::noboolalpha; //Prints 1 & 0 instead of true and false

    std::cout << " number1 < number2 : " << (number1 < number2) << std::endl; //1
    std::cout << " number1 <= number2 : " << (number1 <= number2) << std::endl; //1
    std::cout << " number1 > number2 : " << (number1 > number2) << std::endl; //0
    std::cout << " number1 >= number2 : " << (number1 >= number2) << std::endl; //0
    std::cout << " number1 == number2 : " << (number1 == number2) << std::endl; //0
    std::cout << " number1 != number2 : " << (number1 != number2) << std::endl; //1

    //Results of relational operators stored as booleans
    std::cout << std::endl;
    bool result{(number1 == number2)};
    std::cout << std::boolalpha;
    std::cout << number1 << " == " << number2 << " is " << result << std::endl;


    return 0;
}