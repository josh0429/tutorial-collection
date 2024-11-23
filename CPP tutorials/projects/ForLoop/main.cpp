#include <iostream>

int main()
{
    /* for loop syntax
    for (initialized iterator, condition, increment iterator)
    {
        <Do stuff..>
    }
    We can also initialize the iterator outside the for loop, e.g.,
    int j{};
    for (j; j < 10; j++)
    {
        <Do stuff..>
    }
    std::cout << "j value : " << j
    */
    for (unsigned int i{}; i < 10; i++)
    {
        std::cout << "I love C++" << std::endl;
    }

    for (size_t i{}; i < 10; i++) //Alternative way
    {
        std::cout << "I love C++" << std::endl;
    }
    //size_t vs unsigned int has something to do with the maximum size the iterator value can be.
    //Apparently using size_t is standard, so just use it.
    std::cout << "sizeof(size_t) : " << sizeof(size_t) << std::endl;
    std::cout << "sizeof(unsigned int) : " << sizeof(unsigned int) << std::endl;

    return 0;
}