#include <iostream>
#include <limits>

int main()
{
    std::cout << "The range for short is from " << std::numeric_limits<short>::min() << " to "
        << std::numeric_limits<short>::max() << std::endl;
    
    std::cout << "The range for int is from " << std::numeric_limits<int>::min() << " to "
        << std::numeric_limits<int>::max() << std::endl;

    std::cout << "The range for unsigned int is from " << std::numeric_limits<unsigned int>::min() << " to "
        << std::numeric_limits<unsigned int>::max() << std::endl;

    std::cout << "The range for signed int is from " << std::numeric_limits<signed int>::min() << " to "
        << std::numeric_limits<signed int>::max() << std::endl;
    
    std::cout << "The range for float is from " << std::numeric_limits<float>::min() << " to "
        << std::numeric_limits<float>::max() << std::endl;

    std::cout << "The range for double is from " << std::numeric_limits<double>::min() << " to "
        << std::numeric_limits<double>::max() << std::endl;

    std::cout << "The range for long is from " << std::numeric_limits<long>::min() << " to "
        << std::numeric_limits<long>::max() << std::endl;

    //Read more on the numeric_limits library by looking up "numeric limits"
    return 0;
}