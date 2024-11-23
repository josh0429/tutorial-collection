#include <iostream>

//Function that takes a single parameter, and doesn't
//give back the result explicitly
void enter_bar(unsigned int age)
{
    if(age > 18)
    {
        std::cout << "You're " << age << " years old. Please proceed." << std::endl;
    }
    else
    {
        std::cout << "Sorry, you're too young for this. No offense!" << std::endl;
    }
    return;
}

//Function that takes multiple parameters and returns the result of the computation
double max(double a, double b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

//Function that doesn't take parameters and returns nothing
void say_hello()
{
    std::cout << "Hello there" << std::endl;
    return;
}

//Function that takes no parameters and return something
int lucky_number()
{
    return 99;
}

int main()
{
    enter_bar(22);
    enter_bar(15);

    double result = max(100.50,20);
    std::cout << "max : " << result << std::endl;

    int number{};
    number = lucky_number();
    std::cout << "lucky number : " << number << std::endl;

    say_hello();
    return 0;
}