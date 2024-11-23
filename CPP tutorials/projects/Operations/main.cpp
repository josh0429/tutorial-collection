#include <iostream>

int main()
{
    //Addition
    int number1{2};
    int number2{7};

    int result{number1 + number2};
    std::cout << "result : " << result << std::endl;

    //Subtraction
    result = number2 - number1;
    std::cout << "result : " << result << std::endl;
    result = number1 - number2;
    std::cout << "result : " << result << std::endl;

    //Multiplication
    result = number1 * number2;
    std::cout << "result : " << result << std::endl;

    //Integer Division
    result = number2 / number1;
    std::cout << "result : " << result << std::endl; //Outputs 3 since result is initialized as integer

    //Modulus: Works only on integer types
    result = number2 % number1;
    std::cout << "result : " << result << std::endl;

    //Double Division
    double number3{7};
    double number4{2};
    double result2{number3 / number4};

    std::cout << "result2 : " << result2 << std::endl;

    return 0;
}