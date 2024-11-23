#include <iostream>
#include <fftw3.h>

/*
Syntax:

fftw_complex* in; //Declaring a pointer variable "in" of type "fftw_complex"
    fftw_complex* out; //Declaring a pointer variable "out" of type "fftw_complex"
    fftw_plan p; //Declares fftw plan

    ...

    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N); //Allocates memory to the input array with
        // number of elements N
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N); //Allocates memory to the output array with
        // number of elements N
    p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE); //Creates the plan for the transform
        //1st argument: the size of the transform you are trying to compute. Sizes that are products of 
        //small primes are most efficient.
        //2nd and 3rd arguments: pointers to the input and output arrays of the transform
        //4th argument: can be either "FFTW_FORWARD" or "FFTW_BACKWARD" which indicates the sign of the
        //exponent in the transform (-1 or +1 respectively).
        //5th argument: either "FFTW_MEASURE" or "FFTW_ESTIMATE". For programs with many transforms of the
        //same size, use "FFTW_MEASURE". Otherwise, use "FFTW_ESTIMATE".
    ...
    fftw_execute(p); //Executes the plan. Repeat as needed. Results are stored in the array out
    ...
    fftw_destroy_plan(p); //Deallocates the plan
    fftw_free(in); fftw_free(out); //Also needed to deallocate the plan if you use "fftw_malloc"

*/


int main()
{
    return 0;
}

/*
//Declare arrays using <variable type> <variable_name>[<size_of_array>]
    int scores[10]; //Declaring an array storing 10 integers

    //Reading values
    std::cout << std::endl;
    std::cout << "Reading out scores values (manually) : " << std::endl;

    std::cout << "scores[0] : " << scores[0] << std::endl;
    std::cout << "scores[1] : " << scores[1] << std::endl;
    std::cout << "scores[2] : " << scores[2] << std::endl;
    std::cout << "scores[3] : " << scores[3] << std::endl;
    std::cout << "scores[4] : " << scores[4] << std::endl;
    std::cout << "scores[5] : " << scores[5] << std::endl;
    std::cout << "scores[6] : " << scores[6] << std::endl;
    std::cout << "scores[7] : " << scores[7] << std::endl;
    std::cout << "scores[8] : " << scores[8] << std::endl;
    std::cout << "scores[9] : " << scores[9] << std::endl;

    //Looping through an array
    std::cout << std::endl;
    std::cout << "Looping through scores values : " << std::endl;
    for (size_t i{}; i < 10; i++)
    {
        std::cout << "scores[" << i << "] : " << scores[i] << std::endl;
    }

    //Writing data in an array manually

    std::cout << std::endl;
    std::cout << "Writing data to an array manually : " << std::endl;
    
    scores[0] = 20;
    scores[1] = 21;
    scores[2] = 22;
    scores[3] = 28;
    scores[4] = 12;
    scores[5] = 16;
    scores[6] = 28;
    scores[7] = 30;
    scores[8] = 19;
    scores[9] = 10;

    for (size_t i{}; i < 10; i++)
    {
        std::cout << "scores[" << i << "] : " << scores[i] << std::endl;
    }

    //Writing data in an array with a loop
    std::cout << std::endl;
    std::cout << "Writing data to an array using a loop : " << std::endl;

    for (size_t i{}; i < 10; i++)
    {
        scores[i] = i*3;
    }

    for (size_t i{}; i < 10; i++)
    {
        std::cout << "scores[" << i << "] : " << scores[i] << std::endl;
    }

    //Declaring and initializing arrays
    std::cout << std::endl;
    std::cout << "Declaring and initializing at the same time : " << std::endl;
    
    double salaries[3]{20,60,80};

    for (size_t i{}; i < 3; i++)
    {
        std::cout << "salaries[" << i << "] : " << salaries[i] << std::endl;
    }

    //If you don't initialize all the elements, the others are initialized to 0
    //Initializing by omitting size: int class_sizes[] {10,20,30,40,50};

    //Operations on data stored in arrays
    std::cout << std::endl;
    std::cout << "Operations on data in arrays : " << std::endl;

    int sum{};

    scores[0] = 20;
    scores[1] = 21;
    scores[2] = 22;
    scores[3] = 28;
    scores[4] = 12;
    scores[5] = 16;
    scores[6] = 28;
    scores[7] = 30;
    scores[8] = 19;
    scores[9] = 10;

    for (int element : scores) //Use this syntax to run over the whole array of which we don't know the size
    {
        sum += element;
    }
    std::cout << "Score total : " << sum << std::endl;

    //Querying the size of the array
    std::cout << "scores size : " << std::size(scores) << std::endl;


*/