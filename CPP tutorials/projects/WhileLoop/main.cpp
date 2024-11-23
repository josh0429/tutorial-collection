#include <iostream>

int main()
{
    const unsigned int COUNT{10};

    unsigned int i{};

    std::cout << "Method 1" << std::endl;
    while (i < COUNT)
    {
        std::cout << "COUNT " << i++ << " : I love C++" << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "Method 2" << std::endl;
    i = 0;
    while (i < COUNT)
    {
        std::cout << "COUNT " << i << " : I love C++" << std::endl;
        i++; //or ++i
    }

    return 0;
}