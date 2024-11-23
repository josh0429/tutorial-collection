#include <iostream> //syntax for standard library

int main()
{
    //Declaring pointers
    int* p_number{}; //can only store an address of a variable of type int
    double* p_fractional_number{}; //can only store an address of a variable of type double

    //All pointer variables have the same size
    std::cout << "Size of number pointer : " << sizeof(p_number) << ", size of int : " 
        << sizeof(int) << std::endl;
    std::cout << "Size of fractional_number pointer : " << sizeof(p_fractional_number) << ", size of double : " 
        << sizeof(double) << std::endl;

    //Initializing pointers and assigning them data
    int int_var{43};
    int* p_int{&int_var}; //p_int stores the address of int_var, which is &int_var

    std::cout << "Int var : " << int_var << std::endl;
    std::cout << "p_int (Address in memory) : " << p_int << std::endl; 
    return 0;
}
