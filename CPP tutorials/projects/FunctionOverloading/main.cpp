#include <iostream> //syntax for standard library
int max(int a, int b);
double max(double a, double b);

int main()
{
    int x{125};
    int y{332};
    double w{26.83};
    double z{623.65};
    int maximum1 = max(x,y);
    double maximum2 = max(w,z);

    std::cout << "max(" << x << "," << y << ") : " << maximum1 << std::endl;
    std::cout << "max(" << w << "," << z << ") : " << maximum2 << std::endl;
    return 0;
}

//Running same function differently for DIFFERENT PARAMETERS (either different type, order, or number)
int max(int a, int b)
{
    return (a > b)? a : b ;
}

double max(double a, double b)
{
    return (a > b)? a : b ;
}