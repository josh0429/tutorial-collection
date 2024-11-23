#include <iostream>

int main()
{
    int number1{55};
    int number2{60};

    bool result = (number1 > number2); //Expression yielding the condition
    std::cout << std::boolalpha << "result : " << result << std::endl;

    std::cout << std::endl;
    std::cout << "free standing if statement" << std::endl;

    if(result)
    {
        std::cout << number1 << " is less than " << number2 << std::endl;
    }

    if(!result)
    {
        std::cout << number1 << " is NOT less than " << number2 << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Using expression as condition : " << std::endl;

    if(number1 < number2)
    {
        std::cout << number1 << " is less than " << number2 << std::endl;
    }
    else
    {
        std::cout << number1 << " is NOT less than " << number2 << std::endl;
    }

    //Nested conditions
    std::cout << std::endl;
    std::cout << "Nested conditions : " << std::endl;

    bool red{false};
    bool green{true};
    bool yellow{false};
    bool police_stop{true};

    std::cout << "red = " << red << std::endl;
    std::cout << "green = " << green << std::endl;
    std::cout << "yellow = " << yellow << std::endl;
    std::cout << "police_stop = " << police_stop << std::endl;

    if(green)
    {
        if(police_stop)
        {
            std::cout << "Stop" << std::endl;
        }
        else
        {
            std::cout << "Go" << std::endl;
        }
    }

    //Nesting alternative
    if(green && !police_stop)
    {
        std::cout << "Go" << std::endl;
    }
    else{
        std::cout << "Stop" << std::endl;
    }
    return 0;
}