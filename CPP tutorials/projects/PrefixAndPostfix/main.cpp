#include <iostream>

int main()
{
    int value{5};
    std::cout << "The value is (incrementing) : " << value << std::endl;
    value = value + 1;
    std::cout << "The value is : " << value << std::endl;

    //Postfix
    value = 5;
    std::cout << "The value is (incrementing) : " << value++ << std::endl; //After printing, add 1
    std::cout << "The value is : " << value << std::endl;

    value = 5;
    std::cout << "The value is (decrementing) : " << value-- << std::endl; //After printing, subtract 1
    std::cout << "The value is : " << value << std::endl;

    //Prefix
    value = 5;
    ++value;
    std::cout << "The value is (prefix++) : " << value << std::endl;

    value = 5;
    --value;
    std::cout << "The value is (prefix--) : " << value << std::endl;

    value = 5;
    std::cout << "The value is (prefix++ in line) : " << ++value << std::endl; //6

    value = 5;
    std::cout << "The value is (prefix-- in line) : " << --value << std::endl; //4

    return 0;
}