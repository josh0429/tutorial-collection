#include <iostream>

int main()
{
    //Do-while loops run the body of code AT LEAST ONCE. It runs the body, then checks the condition
    const unsigned int COUNT{10};

    size_t i{};

    do
    {
        std::cout << i++ << " : I love C++" << std::endl;
    }while(i < COUNT);

    return 0;
}