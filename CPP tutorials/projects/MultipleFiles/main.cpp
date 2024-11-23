#include <iostream> //syntax for standard library
#include "compare.h" //syntax for custom-made library

/*
When putting functions in different files, declarations are put in (can be multiple) ".h" files, while
implementations are put in (can be multiple) ".cpp" files. To compile these files, put "#include <name>.h" 
at the start of the code.

Note: header filename and cpp filename need not be the same. As long as the implementations are contained
in any cpp file in the workspace.

Important: make sure that in your "tasks.json" file, you have "${workspaceFolder}.cpp" in the
args section instead of "${file}". At least this is for the particular case of clang++ with MacOS.
This might work differently for other compilers or other operating systems.
*/

int main()
{
    int a{33};
    int b{48};

    int maximum = max(a,b);
    int minimum = min(a,b);

    std::cout << "max(" << a << "," << b << ") : " << maximum << std::endl;
    std::cout << "min(" << a << "," << b << ") : " << minimum << std::endl;
    return 0;
}
