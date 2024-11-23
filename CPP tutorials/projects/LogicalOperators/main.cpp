#include <iostream>

int main()
{
    bool a{true};
    bool b{false};
    bool c{true};
    bool d{false};

    std::cout << std::boolalpha;
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    std::cout << "c : " << c << std::endl;
    std::cout << "d : " << d << std::endl;

    //Logical AND
    std::cout << std::endl;
    std::cout << "Basic AND operations" << std::endl;

    std::cout << "a && b : " << (a && b) << std::endl; //false
    std::cout << "a && c : " << (a && c) << std::endl; //true
    std::cout << "b && c : " << (c && b) << std::endl; //false
    std::cout << "a && b && c : " << (a && b && c) << std::endl; //false

    //Logical OR
    std::cout << std::endl;
    std::cout << "Basic OR operations" << std::endl;

    std::cout << "a || b : " << (a || b) << std::endl; //true
    std::cout << "a || d : " << (a || d) << std::endl; //true
    std::cout << "b || d : " << (b || d) << std::endl; //false
    std::cout << "a || b || d : " << (a || b || d) << std::endl; //true

    //Logical NOT: Negates operand next to it
    std::cout << std::endl;
    std::cout << "Basic NOT operations" << std::endl;

    std::cout << "!a : " << !a << std::endl; //false
    std::cout << "!b : " << !b << std::endl; //true
    std::cout << "!c : " << !c << std::endl; //false

    //Combining logical operators
    std::cout << std::endl;
    std::cout << "Combining logical operators" << std::endl;

    std::cout << "!(a && b) || c : " << (!(a && b) || c) << std::endl; //true

    //Combining logical and relational operators
    std::cout << std::endl;
    std::cout << "Combining logical and relational operators" << std::endl;
    
    int e{45};
    int f{20};
    int g{11};

    std::cout << "e : " << e << std::endl;
    std::cout << "f : " << f << std::endl;
    std::cout << "g : " << g << std::endl;

    std::cout << std::endl;

    std::cout << "(e < f) && (f < g) : " << ((e < f) && (f < g)) << std::endl; //false
    std::cout << "(e > f) && (f > g) : " << ((e > f) && (f > g)) << std::endl; //true
    return 0;
}