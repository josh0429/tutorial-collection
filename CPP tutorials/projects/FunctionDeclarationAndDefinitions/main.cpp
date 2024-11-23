#include <iostream>
/*
    We can separate out the function definition from the function declaration
*/

int max(int a, int b); //Function header/declaration (AKA prototype)
/*
Alternative:
int max(int, int);
*/


int main()
{
    int a{3};
    int b{4};

    std::cout << "max(" << a << "," << b << ") : " << max(a,b) << std::endl;
    return 0;
}

//Function definition
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}