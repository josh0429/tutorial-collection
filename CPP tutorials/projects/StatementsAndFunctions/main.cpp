#include <iostream>

int addNumbers(int firstNumber, int secondNumber)
{
    int result = firstNumber + secondNumber;
    return result;
}

int main()
{
    int first_number {13};
    int second_number {7};
    int third_number {20};
    int fourth_number {72};

    std::cout << "First number : " << first_number << std::endl;
    std::cout << "Second number : " << second_number << std::endl;

    int sum = first_number + second_number;
    std::cout << "Sum : " << sum << std::endl;
    std::cout << "Sum is also : " << addNumbers(first_number,second_number) << std::endl;
    std::cout << "The sum of " << third_number << " and " << fourth_number << " is : " << addNumbers(third_number,fourth_number) << std::endl;

    return 0;
}