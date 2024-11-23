#include <iostream>
#include <string>

//Tools
const int Pen{10}; //const prevents compiler from modifying value of variable.
const int Marker{20};
const int Eraser{30};
const int Rectangle{40};
const int Circle{50};
const int Ellipse{60};

int main()
{
    //Switch is alternative to if else. Though the condition can only be integral types
    int tool{Circle};

    switch (tool)
    {
        case Pen:
        {
            std::cout << "Active tool is pen" << std::endl;
        }
        break;

        case Marker:
        {
            std::cout << "Active tool is Marker" << std::endl;
        }
        break;

        case Eraser:
        {
            std::cout << "Active tool is Eraser" << std::endl;
        }
        break;

        case Rectangle:
        {
            std::cout << "Active tool is Rectangle" << std::endl;
        }
        break;

        case Circle:
        {
            std::cout << "Active tool is Circle" << std::endl;
        }
        break;

        case Ellipse:
        {
            std::cout << "Active tool is Ellipse" << std::endl;
        }
        break;

        default:
        {
            std::cout << "Can't match any tool!" << std::endl;
        }
    }
    std::cout << "Moving on" << std::endl;

    //Putting non-Integral types on switch:
    /*
    std::string name{"Joshua"};
    switch (name) <- Gives Compiler error
    {

    }
    */
    std::string name{"James"};
    const std::string name1{"James"};

    if (name == name1)
    {
        std::cout << "Hello James!" << std::endl;
    }
    else
    {
        std::cout << "Sorry, do I know you?" << std::endl;
    }
    std::cout << "Goodbye." << std::endl;
    return 0;
}