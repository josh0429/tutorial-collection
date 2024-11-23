#include <iostream>
#include <fstream>
#include <fftw3.h> 
#include <cmath>

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

const double PI = 3.14159265359;

int main()
{
    int i;
    const int Npts = 16;
    fftw_complex* in; //Complex array of double[2]. real part: in[i][0]; imaginary part: in[i][1].
    fftw_complex* out; //Complex array of double[2]. real part: out[i][0]; imaginary part: out[i][1].
    fftw_plan p;

    /* Setting up of fftw plan */
    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * Npts);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * Npts);
    p = fftw_plan_dft_1d(Npts, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    /* 
        Setting up of cosine wave:
        Note that in the definition below, our function is defined on the domain [0,T] where T=1. In this
        case, the frequency sampling interval is delta_nu = 1/T = 1. Hence, we should expect a peak at 
        out[3][0], since index k=3 is the one that corresponds to frequency value 3: nu_3 = 3*delta_nu = 3.
    */
    for(i = 0; i < Npts; i++)
    {
        in[i][0] = cos(3 * 2 * PI * i/Npts); //Real part of input
        in[i][1] = 0; //Imaginary part of input
    }

    /* Executing of fourier transform */
    fftw_execute(p);

    /* Printing of result */
    std::cout << std::endl;
    for(i = 0; i < Npts; i++)
    {
        printf("T = 1, freq: %3d %+9.5f %+9.5f I\n", i, out[i][0], out[i][1]);
    }

    /*
        Cosine wave with different domain:
        In the following, we instead define our domain to be [0,T] with T = 1/3, which is the period of our
        cosine function. We retain the same number of time domain samples Npts. We should now expect a peak
        at out[1][0] (and at out[15][0] corresponding to the negative frequency).
    */

    for(i = 0; i < Npts; i++)
    {
        in[i][0] = cos(3 * 2 * PI * i/(3*Npts));
        in[i][1] = 0;
    }

    /* Executing of fourier transform */
    fftw_execute(p);

    /* Printing of result */
    std::cout << std::endl;
    for(i = 0; i < Npts; i++)
    {
        printf("T = 1/3, freq: %3d %+9.5f %+9.5f I\n", i, out[i][0], out[i][1]);
    }

    /* 
        Leakage problems 
        If we define our domain [0,T] such that T is not an integer multiple of the functions period, then we 
        will have leakage problems wherein some of the magnitudes of the transform "leak" into the neighboring
        frequencies. We illustrate this below for a function with period 2*pi/3. We should expect a peak at
        around nu = 3/(2*pi) ~= 0.477. Our domain is [0,T] with T=4. Then, delta nu_k = 1/4 = 0.25 so the peak
        should occur at around nu_k ~ 0.5 or k = 2 (and of course, k = Npts-2 = 14).
    */

    for(i = 0; i < Npts; i++)
    {
        in[i][0] = 5*cos(3 * 4*i/Npts);
        in[i][1] = 0;
    }

    /* Executing of fourier transform */
    fftw_execute(p);

    /* Printing of result */
    std::cout << std::endl;
    for(i = 0; i < Npts; i++)
    {
        printf("(with leakage) freq: %3d %+9.5f %+9.5f I\n", i, out[i][0], out[i][1]); //Note leakage around
        //neighboring frequencies
    }

    fftw_destroy_plan(p);
    fftw_free(in); fftw_free(out);
    

    return 0;
}