#include <iostream>
#include <cmath>

//Lookup "cmath" library for more information

int main()
{
    double weight{7.7};

    //floor
    std::cout << "Weight rounded to floor is : " << std::floor(weight) << std::endl;

    //ceil
    std::cout << "Weight rounded to ceil is : " << std::ceil(weight) << std::endl;

    //abs
    double savings{-5000};

    std::cout << "Abs of weight is : " << std::abs(weight) << std::endl;
    std::cout << "Abs of savings is : " << std::abs(savings) << std::endl;

    //exp: f(x) = e ^ x
    double exponential = std::exp(10);
    std::cout << "The exponential of 10 is : " << exponential << std::endl;

    //pow: pow(base,exponent)
    std::cout << "3 ^ 4 is : " << std::pow(3,4) << std::endl;
    std::cout << "9 ^ 3 is : " << std::pow(9,3) << std::endl;
    std::cout << "4.75 ^ 2.4 is : " << std::pow(4.75,2.4) << std::endl;
    return 0;
}