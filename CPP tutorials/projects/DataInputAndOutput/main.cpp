#include <iostream>
#include <string>

int main()
{
    std::cout << "Hello C++20" << std::endl;
     /*
    int age {21};
    std::cout << "Age : " << age << std::endl;

    std::cerr << "Error message : Something is wrong" << std::endl;
    std::clog << "Log message : Something happened" << std::endl;

    */

    /*
    Getting data from the terminal
    int age1;
    std::string name; //Defines a String variable name

    std::cout << "Please type in your name and age : " << std::endl;
    
    std::cin >> name; //User input gets put into name
    std::cin >> age1; //User input gets put into age1
    
    std::cin >> name >> age1; //Same as two lines above
    std::cout << "Hello " << name << "! You are " << age1 << " years old!" << std::endl;
    */
    
    //Data with spaces
    std::string full_name;
    int age3;

    std::cout << "Please type in your full name and age." << std::endl;

    std::getline(std::cin,full_name); //Gets the full line of user input.
    std::cin >> age3;

    std::cout << "Hello " << full_name << "! You are " << age3 << " years old!";

    return 0;
}